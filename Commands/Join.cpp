#include "../Server/Server.hpp"


void    Server::Join(int index, int id)
{
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == commands[index + 1])
		{
            for (int j = 0; j < channels[i].getClients().size(); ++j)
            {
                if (channels[i].getClients()[j].getUserName() ==  clients[id].getUserName())
                {
                    std::cout <<"channels[i]: " << channels[i].getClients()[j].getUserName() << std::endl;
                    std::cout <<"clients[index]: " << clients[index].getUserName() << std::endl;
                    std::cout << "You are already in this channel" << std::endl;
                    return;
                }
            }
		}
	}

    Channel channel(commands[index + 1]);
    channel.addClient(clients[index]);
    channels.push_back(channel);
    std::cout << "channel:::: " << commands[index + 1] << std::endl;
    clients[id].print(":" + clients[id].getUserName() + "!" + clients[id].getUserName() + "@" + clients[id].getIp() + " JOIN " + commands[index + 1] + "\r\n");
}
