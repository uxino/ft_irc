#include "../Server/Server.hpp"


void    Server::Join(int index, int id)
{

    // kullanıcı daha önce bu kanalda mı değil mi kontrol edilecek
    // kanal oluşturulduğunda yeni bir channel classından veri oluşturmalı
    
    // Channel channel


    clients[id].print(":" + clients[id].getUserName() + "!" + clients[id].getUserName() + "@" + clients[id].getIp() + " JOIN " + commands[index + 1] + "\r\n");

}
