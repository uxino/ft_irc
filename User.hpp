#pragma once

#include "Libraries.hpp"

class User
{
	private:
		int 		socket;
		std::string name;
		std::string n_name;
		std::string r_name;
		std::string message;
		std::string pass;
	public:
		User();
		std::string getName();
		std::string getNickname();
		std::string getRealName();
		std::string getMessage();
		std::string getPass();
		int getSocket();

		void setName(std::string str);
		void setPass(std::string str);
		void setNickname(std::string str);
		void setRealName(std::string str);
		void  setSocket(int socket);
		void setMessage(std::string str);
		~User();
};
