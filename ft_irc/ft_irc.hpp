
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
#include <vector>

// Structure to hold information about each client
struct ClientInfo {
    std::string nickname;
    std::string username;
	bool authorized;
};

// Structure to hold information about each channel
struct Channel {
    std::string name;
    std::vector<int> users;     // A set of all the socket fds of users in this channel
    std::vector<int> operators; // A set of all the socket fds of operators in this channel
};
