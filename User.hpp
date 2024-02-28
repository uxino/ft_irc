#pragma once

#include "Libraries.hpp"

class User
{
	private:
		int 		socket;
		std::string name;
		std::string n_name;
		std::string message;
		std::string pass;
		std::string ip;

	public:
		User();
		std::string getName();
		std::string getIp();
		std::string getNickname();
		std::string getMessage();
		std::string getPass();
		int			getSocket();

		void		setName(std::string str);
		void		setPass(std::string str);
		void		setIp(std::string str);
		void		setNickname(std::string str);
		void		setSocket(int socket);
		void		setMessage(std::string str);
		~User();
};
