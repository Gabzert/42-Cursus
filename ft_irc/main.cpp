#include "ft_irc.hpp"

int main(int argc, char *argv[]) {
	if (argc != 3) {
			std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
			return 1;
	}

	// Get the port number from command-line arguments
	int port = std::atoi(argv[1]);

	ServerData server;

	server.connected_clients = 0;
		server.password = argv[2];

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



	//initialize the server
	serverInit(server, port);

	// Add the server socket to the pollfd array
	client_sockets[0].fd = server.socket;
	client_sockets[0].events = POLLIN;



	// Run the server loop
	while (true) {

		std::cout << "Waiting for clients..." << std::endl;

		login(server, client_sockets, client_info);

		// Process data from a client
		for (int i = 1; i <= server.connected_clients; i++) {
			if (client_sockets[i].revents & POLLIN) {
				// Read data from the client
				char buffer[512] = {0};
				int bytes_read = read(client_sockets[i].fd, buffer, 511);
				if (bytes_read <= 0) {
					// Client has either closed connection or an error occurred
					close(client_sockets[i].fd);
					client_sockets[i].fd = 0;
					client_info.erase(i);
				}
				else
				{
					// Process the command
					std::string command(buffer);
					trimInput(command);
					if (command.substr(0, 4) == "PING")
						ping(i, command, client_sockets);
					else if (command.substr(0, 5) == "NICK ") {
						client_info[i].nickname = command.substr(5);
					}
					else if (command.substr(0, 5) == "USER ") {
						client_info[i].username = command.substr(5);
					}
					// If the command is JOIN, add the user to the specified channel
					else if (command.substr(0, 5) == "JOIN ") 
						join(i, command, client_info, channels);
					// If the command is PRIVMSG, send a message to the specified user or channel
					else if (command.substr(0, 8) == "PRIVMSG ")
						message(i, command, client_info, channels);
					else if (command.substr(0, 5) == "KICK ")
						kick(i, command, client_info, channels);
					else if (command.substr(0, 7) == "INVITE ")
						invite(i, command, client_info, channels);
					else if (command.substr(0, 6) == "TOPIC ")
						topic(i, command, client_info, channels);
					else if (command.substr(0, 5) == "MODE ")
						mode(i, command, client_info, channels);
				}
			}
		}
	}
	return 0;
}
