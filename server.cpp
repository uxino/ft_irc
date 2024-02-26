#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include "User.hpp"
#include "Parse.hpp"

#define PORT 6661
#define MAX_CLIENTS 10

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int server_fd, new_socket, max_clients = MAX_CLIENTS;
    int client_sockets[MAX_CLIENTS] = {0};
    fd_set readfds;
    struct sockaddr_in address;
    ssize_t valread;


    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    if ((bind(server_fd, (struct sockaddr *)&address, sizeof(address))) < 0)
    {
        perror("bind failed!");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed!");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;
	
    while (1)
    {
        FD_ZERO(&readfds); // Dosya tanımlayıcı kümesini temizle
    	char buffer[1024] = {0};

        // Ana soketi kümesine ekle
        FD_SET(server_fd, &readfds);
        int max_sd = server_fd;

        // Client soketlerini kümesine ekle
        for (int i = 0; i < max_clients; i++)
        {
            int sd = client_sockets[i];

            if (sd > 0)
                FD_SET(sd, &readfds);

            if (sd > max_sd)
                max_sd = sd;
        }

        // Select fonksiyonunu kullanarak soket olaylarını bekleyin
        int activity = select(max_sd + 1, &readfds, nullptr, nullptr, nullptr);
        if ((activity < 0) && (errno != EINTR))
            perror("Select error");

        // Yeni bir bağlantı var mı kontrol et
        if (FD_ISSET(server_fd, &readfds))
        {
            if ((new_socket = accept(server_fd, nullptr, nullptr)) < 0)
            {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            std::cout << "New connection, socket fd is " << new_socket << std::endl;

            // Yeni bağlantıyı client soketler dizisine ekle
            for (int i = 0; i < max_clients; i++)
            {
                if (client_sockets[i] == 0)
                {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        }

        // Client soketlerinden gelen verileri kontrol et
        for (int i = 0; i < max_clients; i++)
        {
            int sd = client_sockets[i];
            if (FD_ISSET(sd, &readfds))
            {
                valread = recv(sd, buffer, sizeof(buffer), 0);
				user_info_parse(buffer);
                if (valread == 0)
                {
                    // Bağlantı kapatıldıysa
                    getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&address);
                    std::cout << "Host disconnected, ip " << inet_ntoa(address.sin_addr) << ", port " << ntohs(address.sin_port) << std::endl;
                    close(sd);
                    client_sockets[i] = 0;
                }
                else
                {
                    // Gelen mesajı göster
                    std::cout << buffer << std::endl << std::endl << std::endl;
					// int esad31 = 0;
                    // if ((esad31 = send(sd, ":museker \r\n", 500, 0)) == -1)
					// 	std::cout << "elma armut: " << esad31 << std::endl;
					// ":" + server->getHostname() + " " + reply.first
					//  + " " + user->getNickname() + " " + reply.second
                }
            }
        }
    }
    return 0;
}
