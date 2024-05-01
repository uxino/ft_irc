#include "../Server/Server.hpp"



void	Server::Notice(int index, int id)
{
    std::string message = "";
	int	channel_index = getChannelIndex(commands[1]);

	std::cout << "commands[2]: (" << commands[2] << ")" << std::endl;
	if (strcmp(commands[2].c_str(), "LAGCHECK") == 0)
		return;
    if (channel_index == -1)
		clients[id].print("NOTICE: There is no channel for this name.\n");
	else
	{

		if (isInChannel(channels[channel_index].getChannelAdmins(), clients[id].getNickName()) == -1)
		{
			clients[id].print("NOTICE: You are not a admin for " + channels[channel_index].getChannelName() + ".\n");
			return;
		}
		for (size_t i = 2; i < this->commands.size(); i++)
    	{
        	message += commands[i];
        	message += " ";
    	}
    	for (size_t i = 0; i < clients.size(); i++)
    	{
    	    if (channels.size() > i && strcmp(commands[1].c_str(), channels[i].getChannelName().c_str()) == 0 && isInChannel(channels[i].getClients(), clients[id].getNickName()) != -1)
    	    {
    	        std::vector<Client> tmp_client = channels[i].getClients();
    	        for (size_t j = 0; j < tmp_client.size(); j++)
				{
    	            if (tmp_client[j].getNickName() != clients[id].getNickName())
    	                tmp_client[j].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + "@" + clients[id].getIp() + " NOTICE " + channels[i].getChannelName() + " :"+ message + "\r\n");
				}
				return;
    	    }
// (nick, username, target, message) (":" + nick + "!" + username + "@localhost NOTICE " + target + " " + message + "\r\n")

    	    // else if (strcmp(clients[i].getNickName().c_str(),commands[1].c_str()) == 0)
			// {
			// 	clients[i].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + "@localhost"+ " PRIVMSG " + clients[i].getNickName() + " :"+ message + "\r\n");
			// 	return;
			// }
    	}
	}
}
