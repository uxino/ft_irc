#include "../Server/Server.hpp"


void    Server::Join(int index, int id)
{
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == commands[index + 1])
		{
            for (int j = 0; j < channels[i].getClients().size(); ++j)
            {
                if (channels[i].getClients()[j].getIp() ==  clients[index].getIp())
                {
                    std::cout << "You are already in this channel" << std::endl;
                    return;
                }
            }
		}
	}
    Channel channel(commands[index + 1]);
    channel.addClient(clients[index]);
    channels.push_back(channel);
    clients[id].print(":" + clients[id].getUserName() + "!" + clients[id].getUserName() + "@" + clients[id].getIp() + " JOIN " + commands[index + 1] + "\r\n");
}
