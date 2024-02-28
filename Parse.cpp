#include "Libraries.hpp"

int where_a_point(std::string str, char c)
{
	int index = str.find(c);
	return (index);
}


void user_info_parse(std::vector<User> &users_v, std::string str, int newu_socket)
{
	std::string pass;
	std::string line;
	std::string nick_n;
	std::string user_n;
	std::string ip;
	std::string name_r;
	std::stringstream ss(str);
	User user;

	(void)users_v;
	// PASS :pass
	// NICK n_mucakmak
	// USER mucakmak 0 10.11.2.6 :11,8mucahit

	// PASS :pass
	// NICK n_museker
	// USER museker 0 localhost :1,8esad

	// USER31: faruktinaz 0 10.11.2.10 :1,11faruk
	// NICK n_faruktinaz
	// USER faruk tinaz 0 10.11.2.10 :1,11faruk

	// USER <username> <mode> <unused> :<realname>
	while (std::getline(ss, line, '\n'))
	{
		if (line.substr(0,4) == "PASS")
			user.setPass(line.substr(6,line.size()));
		else if (line.substr(0,4) == "NICK")
		{
			user.setNickname(line.substr(5,line.size()));
			std::cout << "gelmdimm" << line.substr(5,line.size()) << std::endl;
		}
		else if(line.substr(0,4) == "USER")
		{
			int index = where_a_point(line, '0');
			user.setName(line.substr(5, index - 6));
			user.setIp(line.substr(index + 2, where_a_point(line, ':') - index - 3));
		}
	}
	user.setSocket(newu_socket);
	users_v.push_back(user);
}
