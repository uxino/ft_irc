#include "Libraries.hpp"

int where_is_a_point(std::string str, char c)
{
	int index = str.find(c);
	return (index);
}

std::string		join_parse(std::string str)
{
	std::string name;

	name = str.substr(str.find("#") + 1, 3);
	std::cout << "NAME: " << name << std::endl;
	// std::cout << "index: " << str.find(" ", str.find(" ") + 1) - str.find("#") - 1 << std::endl;
	return (name);
}

int		user_info_parse(std::vector<User> &users_v, std::string str, int newu_socket, std::string arg_pass)
{
	std::string pass;
	std::string line;
	std::string nick_n;
	std::string user_n;
	std::string ip;
	std::string name_r;
	std::stringstream ss(str);
	User user;

	while (std::getline(ss, line, '\n'))
	{
		if (line.substr(0,4) == "PASS")
		{
			if (arg_pass.compare(line.substr(6,line.size())))
				user.setPass(line.substr(6,line.size()));
			else
			{
				std::cout << "Wrong Pass!" << std::endl;
				return (0);
			}
		}	
		else if (line.substr(0,4) == "NICK")
			user.setNickname(line.substr(5,line.size()));
		else if(line.substr(0,4) == "USER")
		{
			int index = where_is_a_point(line, '0');
			user.setName(line.substr(5, index - 6));
			user.setIp(line.substr(index + 2, where_is_a_point(line, ':') - index - 3));
		}
	}
	user.setSocket(newu_socket);
	users_v.push_back(user);
	return (1);
}
