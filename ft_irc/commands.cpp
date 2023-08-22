#include "ft_irc.hpp"

//struct pollfd *client_sockets, std::map<int, ClientInfo> client_info

void ping(int i, std::string command, struct pollfd* client_sockets)
 {
    std::string reply = "PONG " + command.substr(5) + "\r\n";
    send(client_sockets[i].fd, reply.c_str(), reply.size(), 0);
} 

void join(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
    std::string channel_name = command.substr(5);
    channels[channel_name].name = channel_name;
    channels[channel_name].users.insert(client_info[i]);
}

void message(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
    std::string target = command.substr(8, command.find(" :") - 8);
    std::string message = command.substr(command.find(" :") + 2);

    // If the target starts with a #, it's a channel
    if (target[0] == '#') {
        Channel& channel = channels[target];
        for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++)
        {
            ClientInfo user = *it;
            std::string full_msg = ":" + user.nickname + "!~" + user.username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
            send(user.fd, full_msg.c_str(), full_msg.size(), 0);
        }
    }
    // Otherwise, the target is a user
    else {
        for (size_t i = 0; i < client_info.size(); i++) {
            if (client_info[i].nickname == target) {
                std::string full_msg = ":" + client_info[i].nickname + "!~" + client_info[i].username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
                send(client_info[i].fd, full_msg.c_str(), full_msg.size(), 0);
                break;
            }
        }
    }
}

void kick(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
    // Parse the channel and user
    std::string channel_name = command.substr(5, command.find(" ", 5) - 5);
    std::string user_nickname = command.substr(command.find(" ", 5) + 1);

    // Find the channel and user
    Channel& channel = channels[channel_name];
    int user_fd = -1;
    for (size_t i = 0; i < channel.users.size(); i++) {
        if (client_info[i].nickname == user_nickname) {
            break;
        }
    }
    // Check if the command issuer is an operator of the channel
    if (channel.operators.find(client_info[i]) == channel.operators.end()) {
        std::string reply = ": 482 " + client_info[i].nickname + " " + channel_name + " :You're not channel operator\r\n";
        send(client_info[i].fd, reply.c_str(), reply.size(), 0);
    }
    // Check if the user is in the channel
    else if (channel.users.find(client_info[i]) == channel.users.end()) {
        std::string reply = ": 441 " + client_info[i].nickname + " " + user_nickname + " " + channel_name + " :They aren't on that channel\r\n";
        send(client_info[i].fd, reply.c_str(), reply.size(), 0);
    }
    // Otherwise, kick the user
    else {
        channel.users.erase(client_info[i]);
        channel.operators.erase(client_info[i]);
        std::string kick_msg = ":" + client_info[i].nickname + "!~" + client_info[i].username + "@localhost KICK " + channel_name + " " + user_nickname + " :Kicked by " + client_info[i].nickname + "\r\n";
        // Notify all users in the channel
        for (size_t i = 0; i < channel.users.size(); i++) {
            send(client_info[i].fd, kick_msg.c_str(), kick_msg.size(), 0);
        }
        //Notify the kicked user
        send(client_info[i].fd, kick_msg.c_str(), kick_msg.size(), 0);
    }
}