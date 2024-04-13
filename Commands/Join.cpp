#include "../Server/Server.hpp"


void    Server::Join(int index, int id)
{

    // kullanıcı daha önce bu kanalda mı değil mi kontrol edilecek
    // kanal oluşturulduğunda yeni bir channel classından veri oluşturmalı
    
    // Channel channel

	// Channel channel(commands[index + 1]);

	// channels.push_back(channel);
	// channels[id].setChannel();
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == commands[index + 1])
		{
			
		}
	}
    clients[id].print(":" + clients[id].getUserName() + "!" + clients[id].getUserName() + "@" + clients[id].getIp() + " JOIN " + commands[index + 1] + "\r\n");

}
