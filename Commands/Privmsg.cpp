#include "../Server/Server.hpp"

void    Server::Privmsg(int index, int id)
{
    std::string message = "";
	size_t i;
	static int flag = 0;
    for (i = 2; i < this->commands.size(); i++)
    {
        message += commands[i];
        message += " ";
    }

    for (i = 0; i < clients.size(); i++)
    {
        if (channels.size() > i && strcmp(commands[1].c_str(), channels[i].getChannelName().c_str()) == 0)
        {
            std::vector<Client> tmp_client = channels[i].getClients();
            for (size_t j = 0; j < tmp_client.size(); j++)
			{
                if (tmp_client[j].getNickName() != clients[id].getNickName())
                    tmp_client[j].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + '@' + clients[id].getIp() + " PRIVMSG " + channels[i].getChannelName() + " :"+ message + "\r\n");
			}
			return;
        }
        else if (strcmp(clients[i].getNickName().c_str(),commands[1].c_str()) == 0)
		{
			clients[i].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + "@localhost"+ " PRIVMSG " + clients[i].getNickName() + " :"+ message + "\r\n");
            clients[id].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + "@localhost" + " PRIVMSG " + clients[i].getNickName() + " :"+ message + "\r\n");
			return;
		}
    }

}