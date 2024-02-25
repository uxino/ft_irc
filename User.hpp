#pragma once
#include <iostream>

class User
{
	private:
		std::string name;
		std::string n_name;
		std::string r_name;
		std::string ip;
		std::string message;
	public:
		User(std::string name, std::string n_name, std::string r_name);
		std::string getName();
		std::string getNickname();
		std::string getRealName();
		std::string getIp();
		std::string getMessage();
		~User();
};
