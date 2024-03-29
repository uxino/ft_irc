#include "Server.hpp"

std::vector Server::getChannels() { return this->channels; }
std::vector Server::getClients() { return this->clients; }
std::vector Server::getCommands() { return this->commands; }

Server::Server(int port, std::string pass)
{

}