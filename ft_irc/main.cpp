#include "ft_irc.hpp"
#define MAX_CLIENTS 1024 // Maximum number of clients the server will allow




void trimInput(std::string &s)
{
    s.erase(s.find('\n'));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
        return 1;
    }

	int connected_clients = 0;

    // Get the port number from command-line arguments
    int port = std::atoi(argv[1]);

	std::string server_password = argv[2];

	// Map from channel names to channel info
	std::map<std::string, Channel> channels;

	// Map from socket file descriptor to client info
	std::map<int, ClientInfo> client_info;

    // Initialize all client_socket[] to 0 so as not to poll them
    struct pollfd client_sockets[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i].fd = 0;
        client_sockets[i].events = POLLIN;
    }







    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "ERROR: Failed to open socket" << std::endl;
        return 1;
    }

    // Allow the kernel to reuse the port
    int enable = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        std::cerr << "ERROR: setsockopt failed" << std::endl;
        return 1;
    }

    // Create a sockaddr_in struct for the proper port and bind our socket to it
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port); // We will need to convert the port to network byte order
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind our socket to the port
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "ERROR: Failed to bind to socket" << std::endl;
        return 1;
    }

    // Start listening on with the socket
    if (listen(server_socket, 5) < 0) { // The 5 here is the maximum number of backlog connections
        std::cerr << "ERROR: listen failed" << std::endl;
        return 1;
    }

    std::cout << "Server started and listening on port " << port << std::endl;

    // Add the server socket to the pollfd array
    client_sockets[0].fd = server_socket;
    client_sockets[0].events = POLLIN;








    // Run the server loop
    while (true) {

        std::cout << "Waiting for clients..." << std::endl;

        // Poll the sockets for connections
        int poll_count = poll(client_sockets, MAX_CLIENTS, -1);
        if (poll_count < 0) {
            std::cerr << "ERROR: poll failed" << std::endl;
            return 1;
        }

        // If the server_socket has data, then it must be an incoming connection
        if (client_sockets[0].revents & POLLIN) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);

            int new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
            if (new_socket < 0) {
                std::cerr << "ERROR: accept failed" << std::endl;
                return 1;
            }

			 // Wait for a PASS command and validate the password
			char pass_buffer[512] = {0};
			std::string display = "PASS :";
			send(new_socket, display.c_str(), display.size(), 0);
			read(new_socket, pass_buffer, 511);
			// Check if the command is a "PASS" command
			std::string provided_password(pass_buffer);
			trimInput(provided_password);
			// Compare the provided_password with your predefined password
			if (provided_password == server_password) {
				std::cout << "Client authenticated successfully." << std::endl;
				connected_clients++;
				// Set the isAuthenticated flag to true
				client_info[connected_clients].authorized = true;
				
			} else {
				std::cerr << "ERROR: Invalid password provided." << std::endl;
				close(new_socket);
			}
            std::cout << "New client connected" << std::endl;

            // Add the new socket to the pollfd array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i].fd == 0) {
                    client_sockets[i].fd = new_socket;
                    break;
                }
            }
        }

		// Process data from a client
		for (int i = 1; i <= connected_clients; i++) {
			if (client_sockets[i].revents & POLLIN) {
				// Read data from the client
				char buffer[512] = {0};
				int bytes_read = read(client_sockets[i].fd, buffer, 511);
				if (bytes_read <= 0) {
					// Client has either closed connection or an error occurred
					close(client_sockets[i].fd);
					client_sockets[i].fd = 0;
					client_info.erase(i);
				} else {
					// Process the command
					std::string command(buffer);
					trimInput(command);

					// If the command is PING, reply with PONG
					if (command.substr(0, 4) == "PING") {
						std::string reply = "PONG " + command.substr(5) + "\r\n";
						send(client_sockets[i].fd, reply.c_str(), reply.size(), 0);
					} 

					// If the command is NICK, set the user's nickname
					else if (command.substr(0, 5) == "NICK ") {
						client_info[i].nickname = command.substr(5);
					}

					// If the command is USER, set the user's username
					else if (command.substr(0, 5) == "USER ") {
						client_info[i].username = command.substr(5);
					}

					// If the command is JOIN, add the user to the specified channel
					else if (command.substr(0, 5) == "JOIN ") {
						std::string channel_name = command.substr(5);
						channels[channel_name].name = channel_name;
						channels[channel_name].users.push_back(i);
					}

					// If the command is PRIVMSG, send a message to the specified user or channel
					else if (command.substr(0, 8) == "PRIVMSG ") {
						std::string target = command.substr(8, command.find(" :") - 8);
						std::string message = command.substr(command.find(" :") + 2);

						// If the target starts with a #, it's a channel
						if (target[0] == '#') {
							Channel& channel = channels[target];
							for (size_t i = 0; i < channel.users.size(); i++) {
								std::string full_msg = ":" + client_info[i].nickname + "!~" + client_info[i].username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
								send(client_sockets[i].fd, full_msg.c_str(), full_msg.size(), 0);
							}
						}
						// Otherwise, the target is a user
						else {
							for (size_t i = 0; i < client_info.size(); i++) {
								if (client_info[i].nickname == target) {
									std::string full_msg = ":" + client_info[i].nickname + "!~" + client_info[i].username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
									send(client_sockets[i].fd, full_msg.c_str(), full_msg.size(), 0);
									break;
								}
							}
						}
					}
					// TODO: Add handling for other IRC commands here
				}
			}
		}
    }

    return 0;
}
