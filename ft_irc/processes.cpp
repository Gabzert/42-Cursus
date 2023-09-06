#include "ft_irc.hpp"
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void serverInit(ServerData &server, int port)
{
        // Create a socket
    server.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket < 0) {
        std::cerr << "ERROR: Failed to open socket" << std::endl;
        return ;
    }

    // Allow the kernel to reuse the port
    int enable = 1;
    if (setsockopt(server.socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        std::cerr << "ERROR: setsockopt failed" << std::endl;
        return ;
    }

    // Create a sockaddr_in struct for the proper port and bind our socket to it
    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(port); // We will need to convert the port to network byte order
    server.addr.sin_addr.s_addr = inet_addr("127.0.0.1");    //INADDR_ANY;

    // Bind our socket to the port
    if (bind(server.socket, (struct sockaddr *) &server.addr, sizeof(server.addr)) < 0) {
        std::cerr << "ERROR: Failed to bind to socket" << std::endl;
        return ;
    }

    // Start listening on with the socket
    if (listen(server.socket, 5) < 0) { // The 5 here is the maximum number of backlog connections
        std::cerr << "ERROR: listen failed" << std::endl;
        return ;
    }

    std::cout << "Server started and listening on IP 127.0.0.1 and port " << port << std::endl;
}


void login(ServerData &server, struct pollfd *client_sockets, std::map<int, ClientInfo> &client_info)
{
        // Poll the sockets for connections
    int poll_count = poll(client_sockets, MAX_CLIENTS, -1);
    if (poll_count < 0) {
        std::cerr << "ERROR: poll failed" << std::endl;
        return ;
    }

    // If the server_socket has data, then it must be an incoming connection
    if (client_sockets[0].revents & POLLIN) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int new_socket = accept(server.socket, (struct sockaddr *) &client_addr, &client_len);
        if (new_socket < 0) {
            std::cerr << "ERROR: accept failed" << std::endl;
            return ;
        }

        // Wait for a PASS command and validate the password
        char pass_buffer[512] = {0};
        std::string display = "PASS :";
        send(new_socket, display.c_str(), display.size(), 0);
        read(new_socket, pass_buffer, 511);
        // Check if the command is a "PASS" command
        std::string input(pass_buffer);
        trimInput(input);
        // Compare the provided_password with your predefined password
        if (input == server.password) {
            std::cout << "Client authenticated successfully." << std::endl;
            server.connected_clients++;
            // Set the isAuthenticated flag to true
            client_info[server.connected_clients].authorized = true;
            display = "USER :";
            send(new_socket, display.c_str(), display.size(), 0);
            read(new_socket, pass_buffer, 511);
            input = pass_buffer;
            trimInput(input);
            /* possible error checking */
            client_info[server.connected_clients].username = input;
            display = "NICK :";
            send(new_socket, display.c_str(), display.size(), 0);
            read(new_socket, pass_buffer, 511);
            input = pass_buffer;
            trimInput(input);
            /* possible error checking */
            client_info[server.connected_clients].nickname = input;
            std::cout << "New client connected" << std::endl;
            // Add the new socket to the pollfd array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i].fd == 0) {
                    client_sockets[i].fd = new_socket;
                    client_info[server.connected_clients].fd = new_socket;
                    break;
                }
            }
        } else {
            std::cerr << "ERROR: Invalid password provided." << std::endl;
            close(new_socket);
        }
    }
}
