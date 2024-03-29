#include "Server.hpp"

std::vector<Channel> Server::getChannels() { return this->channels; }
std::vector<Client> Server::getClients() { return this->clients; }
std::vector<std::string> Server::getCommands() { return this->commands; }

Server::Server(int port, std::string pass)
{
	
}