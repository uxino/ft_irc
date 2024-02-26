#include "Parse.hpp"

void user_info_parse(std::string str)
{
	std::string pass;
	std::string line;
	std::string nick_n;
	std::string user_n;
	std::string ip;
	std::string name_r;
	std::stringstream ss(str);

	while (std::getline(ss, line, '\n'))
	{
		std::cout << "line: " << line << std::endl;
		if (line.substr(0,4) == "PASS")
			pass = line.substr(4,line.size());
		else if (line.substr(0,4) == "NICK")
			nick_n = line.substr(4,line.size());
		else if(line.substr(0,4) == "USER")
		{
			;
		}
	}

}
