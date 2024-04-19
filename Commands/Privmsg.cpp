#include "../Server/Server.hpp"
#include<string.h>
/*

message from 0: MODE elmaa

message from 0: WHO elmaa

message from 0: MODE elmaa b

message from 0: PRIVMSG elmaa :ben geldim kral

privmsg Pragma Hello! ** burada sadece 1 kişiye mesaj yollanmış
privmsg Pragma,Crocodile Hello to you both! ** burada ise iki kişiye yollanmış
privmsg #kvirc Hello from outside! ** burada channel'a yollanmış

*/

void    Server::Privmsg(int index, int id)
{
    std::string message = "";

    for (size_t i = 2; i < this->commands.size(); i++)
    {
        message += commands[i];
        message += " ";
    }

    for (size_t i = 0; i < clients.size(); i++)
    {
        if ( channels.size() >= i && strcmp(commands[1].c_str(), channels[i].getChannelName().c_str()) == 0)
        {
            std::vector<Client> tmp_client = channels[i].getClients();
            for (size_t j = 0; j < tmp_client.size(); j++)
                if (tmp_client[j].getNickName() != clients[id].getNickName())
                    tmp_client[j].print(":" + clients[id].getNickName() + "!" + clients[id].getUserName() + '@' + clients[id].getIp() + " PRIVMSG " + channels[i].getChannelName() + " :"+ message + "\r\n");
        }
        // else if ()
    }
}
