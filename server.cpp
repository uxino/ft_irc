#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 6662
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
	std::vector<User> users_v;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
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

    std::cout << "Server is listening on port " << port << std::endl;
	
    while (1)
    {
		users_v.clear();
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
					int esad31 = 0;
                    if ((esad31 = send(sd, ":museker \r\n", 500, 0)) == -1)
						std::cout << "elma armut: " << esad31 << std::endl;
					// ":" + server->getHostname() + " " + reply.first
					//  + " " + user->getNickname() + " " + reply.second
                }
            }
        }
    }
    return 0;
}
// çoğu yerde max_client değişkeni yerine o an baglı olan client sayısını tutan bir connected_clients değişken kullansak daha güvenli olur.
// perror & nullptr kullanımı c++98 standartına göre derlendiğinde hata veriyor linux 
// irc serverine baglandıktan sonra disconnect attıgımda irc quit sinyali gönderildi diyor ona göre bi işlem yapmamız lazım sanırım.
// disconnecte zorlayınca da [SOCKET ERROR]: Operation aborted

// benim yazdiklarımın basinda '--' var
/*
[22:39:59] Logging in as fdgn_faruk!faruktt :faruktinaz
[22:39:59] The local IP address as seen by the IRC server is 127.0.0.1
[22:39:59] Login operations complete, happy ircing!
[22:39:59] Welcome to the Internet Relay Network faruktt!faruktt@127.0.0.1
--[22:40:10] [RAW]: nasi
[22:40:16] [][PASS] :123444
[22:40:16] [][USER] faruktt 0 127.0.0.1 :faruktinaz
[22:40:18] [Server parser]: encountered problems while parsing the following message:
[22:40:18] [Server parser]: [127.0.0.1][JOIN] #kvirc
[22:40:18] [Server parser]: Received a join message for an unknown channel, possible desync
--[22:40:21] [][ALO] 
[22:40:21] Received ping from 127.0.0.1 (PING faruktt 127.0.0.1), replied pong
--[22:40:34] [RAW]: alo
[22:40:44] Sent QUIT, waiting for the server to close the connection... **
[22:40:47] [SOCKET ERROR]: Operation aborted
[22:40:47] Connection terminated [127.0.0.1 (127.0.0.1:6000)]
*/

