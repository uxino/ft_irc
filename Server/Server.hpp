#pragma once

#include "../Channel/Channel.hpp"
#include "../Client/Client.hpp"
#include <vector>
#include <iostream>

class Server
{
    private:
        std::vector<Channel>		channels;
        std::vector<Client>			clients;
        std::vector<std::string>	commands;
		std::string					serverIp;
		int 						port;
		int							serverFd;
		int							acceptFd;


    public:
		Server(int port, std::string pass);
		std::vector<Channel> getChannels();
		std::vector<Client> getClients();
		std::vector<std::string> getCommands();
		int			getAcceptFd();
		int			getServerFd();
		int			getPort();
		~Server();

};


