#include "../Server/Server.hpp"
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


    std::cout << "message bu: " << commands[3] << std::endl;
	std::cout << "ben girdim!!!" << std::endl;

    for (int i = 0; i < commands.size(); i++)
        std::cout << ""    

    // for (size_t j = 3; j < this->commands.size(); j++)
    // {
    //     message += " ";
    //     message += commands[j];
    // }

    // clients[i].print(":" + client.getNick() + "!" + client.getUsername() + '@' + client.getRealIp() + " PRIVMSG " + clients[i].getNick() + " :" + message + "\r\n");
    // client.print(":" + client.getNick() + "!" + client.getUsername() + '@' + client.getRealIp() + " PRIVMSG " + clients[i].getNick() + " :" + message + "\r\n");

}
