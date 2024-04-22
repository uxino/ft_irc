#include "../Server/Server.hpp"


void    Server::Join(int index, int id)
{
    int is_exist = 0;

	if (commands[index + 1][0] != '#')
		clients[id].print("JOIN: There is no # in the first character.\n");
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == commands[index + 1])
		{
            for (int j = 0; j < channels[i].getClients().size(); ++j)
            {
                if (channels[i].getClients()[j].getUserName() ==  clients[id].getUserName())
                {
                    std::cout << "You are already in this channel" << std::endl;
                    return;
                }
            }
		}
	}

    for (size_t i = 0; i < channels.size(); i++)
	{
        if (commands[index + 1] == channels[i].getChannelName())
		{		
	    	channels[i].addClient(clients[id]);
            is_exist = 1;
            break;
		}
	}
    if (is_exist == 0)
    {
        Channel channel(commands[index + 1]);

        channel.addClient(clients[id]);
        channels.push_back(channel);
    }
    for (size_t i = 0; i < channels.size(); i++)
    {
        if (channels[i].getChannelName() == commands[index + 1])
        {
            for (size_t j = 0; j < channels[i].getClients().size(); j++)
            {
                channels[i].getClients()[j].print(":" + clients[id].getUserName() + "!" + clients[id].getUserName() + "@"+ clients[id].getIp() + " JOIN " + commands[index + 1] + "\r\n");
                channels[i].getClients()[j].print("MODE " + channels[i].getChannelName() + " +o " + channels[i].getClients()[0].getUserName() + "\r\n");

            }
            for (size_t k = 0; k < channels[i].getClients().size(); k++)
            {
                if (channels[i].getClients()[k].getNickName() != clients[id].getNickName())
                {
                    clients[id].print(":" + channels[i].getClients()[k].getUserName() + "!" + channels[i].getClients()[k].getUserName() + "@localhost" + " JOIN " + commands[index + 1] + "\r\n");
                    clients[id].print("MODE " + channels[i].getChannelName() + " +o " + channels[i].getClients()[0].getUserName() + "\r\n");
                }
            }
        }
    }
    
}
