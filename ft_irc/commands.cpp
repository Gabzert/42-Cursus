#include "ft_irc.hpp"

/**************			  GENERAL COMMANDS					 ********************/

void ping(int i, std::string command, struct pollfd* client_sockets)
 {
	std::string reply = "PONG " + command.substr(5) + "\r\n";
	send(client_sockets[i].fd, reply.c_str(), reply.size(), 0);
} 

void join(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	std::string channel_name = command.substr(5);
	if (channels.find(channel_name) == channels.end())
		channels[channel_name].operators.insert(client_info[i]);
	else {
		if (channels[channel_name].inviteOnly){
			bool found = false;
			for (std::set<int>::iterator it = channels[channel_name].invited.begin(); it !=  channels[channel_name].invited.end(); it++){
				if (client_info[i].fd == *it){
					channels[channel_name].invited.erase(it);
					found = true;
					break;
				}
			}
			if (!found) {
			std::string reply = "You've not been invited in " + channel_name + "\r\n";
			send(client_info[i].fd, reply.c_str(), reply.size(), 0);
			return ;
		}
		}
	}
	channels[channel_name].users.insert(client_info[i]);
}

void message(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	std::string target = command.substr(8, command.find(" :") - 8);
	std::string message = command.substr(command.find(" :") + 2);

	// If the target starts with a #, it's a channel
	if (target[0] == '#') {
		Channel& channel = channels[target];
		if (channel.users.find(client_info[i]) == channel.users.end()) {
			std::string reply = "You're not a member of " + target + "\r\n";
			send(client_info[i].fd, reply.c_str(), reply.size(), 0);
		}
		else {
			for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++)
			{
				ClientInfo user = *it;
				std::string full_msg = ":" + user.nickname + "!~" + user.username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
				send(user.fd, full_msg.c_str(), full_msg.size(), 0);
			}
		}
	}
	// Otherwise, the target is a user
	else {
		for (size_t x = 0; x < client_info.size(); x++) {
			if (client_info[x].nickname == target) {
				std::string full_msg = ":" + client_info[x].nickname + "!~" + client_info[x].username + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
				send(client_info[x].fd, full_msg.c_str(), full_msg.size(), 0);
				break;
			}
		}
	}
}

/**************			  ADMIN COMMANDS					 ********************/

void kick(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	// Parse the channel and user
	std::string channel_name = command.substr(5, command.find(" ", 5) - 5);
	std::string user_nickname = command.substr(command.find(" ", 5) + 1);
	// Find the channel and user
	Channel& channel = channels[channel_name];
	// Check if the command issuer is an operator of the channel
	if (channel.operators.find(client_info[i]) == channel.operators.end()) {
		std::string reply = ": 482 " + client_info[i].nickname + " " + channel_name + " :You're not channel operator\r\n";
		send(client_info[i].fd, reply.c_str(), reply.size(), 0);
		return ;
	}
	// Check if the user is in the channel
	ClientInfo target_user;
	bool found = false;
	for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++) {
		target_user = *it;
		if (target_user.nickname == user_nickname) {
			found = true;
			break;
		}
	}
	if (!found) {
		std::string reply = ": 441 " + client_info[i].nickname + " " + user_nickname + " " + channel_name + " :They aren't on that channel\r\n";
		send(client_info[i].fd, reply.c_str(), reply.size(), 0);
	}
	// Otherwise, kick the user
	else {
		channel.users.erase(target_user);
		channel.operators.erase(target_user);
		std::string kick_msg = ":" + client_info[i].nickname + "!~" + client_info[i].username + "@localhost KICK " + channel_name + " " + user_nickname + " :Kicked by " + client_info[i].nickname + "\r\n";
		// Notify all users in the channel
		for (size_t x = 0; x < channel.users.size(); x++) {
			send(client_info[x].fd, kick_msg.c_str(), kick_msg.size(), 0);
		}
		//Notify the kicked user
		send(target_user.fd, kick_msg.c_str(), kick_msg.size(), 0);
	}
}

void invite(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	std::string user_nickname = command.substr(7, command.find(" ", 7) - 7);
	std::string channel_name = command.substr(command.find(" ", 7) + 1);

	Channel& channel = channels[channel_name];
	if (channel.operators.find(client_info[i]) == channel.operators.end()) {
		std::string reply = "You're not channel operator of " + channel_name + "\r\n";
		send(i, reply.c_str(), reply.size(), 0);
	}
	else {
		for (size_t x = 0; x < client_info.size(); x++) {
			if (client_info[x].nickname == user_nickname) {
				channel.invited.insert(client_info[x].fd);
				std::string invite_msg = client_info[x].nickname + " invites you to " + channel_name + "\r\n";
				send(client_info[x].fd, invite_msg.c_str(), invite_msg.size(), 0);
				break;
			}
		}
	}
}

void topic(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	std::string channel_name = command.substr(6, command.find(" :", 6) - 6);
	std::string new_topic = command.substr(command.find(" :", 6) + 2);

	Channel& channel = channels[channel_name];
	if (channel.topicLock) {
		if (channel.operators.find(client_info[i]) == channel.operators.end()) {
			std::string reply = "You're not channel operator of " + channel_name + "\r\n";
			send(i, reply.c_str(), reply.size(), 0);
			return ;
		}
	}
	if (new_topic.empty()) {
		std::string topic_msg = "Topic for " + channel_name + " is: " + channel.topic + "\r\n";
		send(i, topic_msg.c_str(), topic_msg.size(), 0);
	} else {
		channel.topic = new_topic;
		std::string topic_msg = client_info[i].nickname + " has set the topic for " + channel_name + " to: " + new_topic + "\r\n";
		for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++) {
			ClientInfo user = *it;
			send(user.fd, topic_msg.c_str(), topic_msg.size(), 0);
		}
	}
}

void mode(int i, std::string command, std::map<int, ClientInfo> client_info, std::map<std::string, Channel> channels)
{
	std::string channel_name = command.substr(5, command.find(" ", 5) - 5);
	std::string mode_changes = command.substr(command.find(" ", 5) + 1);

	Channel& channel = channels[channel_name];
	if (channel.operators.find(client_info[i]) == channel.operators.end()) {
		std::string reply = "You're not channel operator of " + channel_name + "\r\n";
		send(i, reply.c_str(), reply.size(), 0);
	} else {
		if (mode_changes == "+o") {
			std::string user_nickname = command.substr(command.find(" ", command.find(" ", 5) + 1) + 1);
			for (size_t x = 0; x < client_info.size(); x++) {
				if (client_info[x].nickname == user_nickname) {
					channel.operators.insert(client_info[x]);
					std::string mode_msg = client_info[x].nickname + " gives channel operator privileges to " + user_nickname + "\r\n";
						for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++) {
							ClientInfo user = *it;
							send(user.fd, mode_msg.c_str(), mode_msg.size(), 0);
						}
					break;
				}
			}
		} else if (mode_changes == "-o") {
			std::string user_nickname = command.substr(command.find(" ", command.find(" ", 5) + 1) + 1);
			for (size_t i = 0; i < client_info.size(); i++) {
				if (client_info[i].nickname == user_nickname) {
					channel.operators.erase(client_info[i]);
					std::string mode_msg = client_info[i].nickname + " removes channel operator privileges to " + user_nickname + "\r\n";
						for (std::set<ClientInfo>::iterator it = channel.users.begin(); it != channel.users.end(); it++) {
							ClientInfo user = *it;
							send(user.fd, mode_msg.c_str(), mode_msg.size(), 0);
						}
					break;
				}
			}
		} else if (mode_changes == "+t"){
			channel.topicLock = true;
		} else if (mode_changes == "-t"){
			channel.topicLock = false;
		} else if (mode_changes == "+i"){
			channel.inviteOnly = true;
		} else if (mode_changes == "-i"){
			channel.inviteOnly = false;
		} else if (mode_changes == "+k"){
			std::string password = command.substr(command.find(" ", command.find(" ", 5) + 1) + 1);
			channel.key = password;
		} else if (mode_changes == "-k"){
			channel.key.clear();
		}
	}
}