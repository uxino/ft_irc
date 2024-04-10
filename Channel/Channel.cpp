#include "Channel.hpp"


Channel::Channel(std::string name) { this->channelName = name; }

std::vector<Client> Channel::getClients() { return this->clients; }

Channel::~Channel() { }
