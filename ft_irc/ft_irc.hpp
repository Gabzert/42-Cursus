
#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <map>
#include <set>
#include <algorithm>
#define MAX_CLIENTS 1024 // Maximum number of clients the server will allow

// Structure to hold information about each client
struct ClientInfo {
    std::string nickname;
    std::string username;
    int fd;
	bool authorized;
};

// Structure to hold information about each channel
struct Channel {
    std::string name;
    std::set<ClientInfo> users;     // A set of all the infos of users in this channel
    std::set<ClientInfo> operators; // A set of all the infos of operators in this channel
};

struct ServerData {
    std::string password;
    int socket;
    int connected_clients;
    struct sockaddr_in addr;
};


void trimInput(std::string &s);
void login(ServerData server, struct pollfd *client_sockets, std::map<int, ClientInfo> client_info);
void serverInit(ServerData server, int port);

/* COMMANDS */

void ping(int i, std::string command, struct pollfd* client_sockets);
void join(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels);
void message(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels);
void kick(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels);

