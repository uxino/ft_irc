#include "../Server/Server.hpp"

// mode format is 
// 4.2.3.1 Channel modes

//    Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>]
//                [<ban mask>]

//    The MODE command is provided so that channel operators may change the
//    characteristics of `their' channel.  It is also required that servers
//    be able to change channel modes so that channel operators may be
//    created.

//    The various modes available for channels are as follows:

//            o - give/take channel operator privileges;
//            p - private channel flag;
//            s - secret channel flag;
//            i - invite-only channel flag;
//            t - topic settable by channel operator only flag;
//            n - no messages to channel from clients on the outside;
//            m - moderated channel;
//            l - set the user limit to channel;
//            b - set a ban mask to keep users out;
//            v - give/take the ability to speak on a moderated channel;
//            k - set a channel key (password).

//    When using the 'o' and 'b' options, a restriction on a total of three
//    per mode command has been imposed.  That is, any combination of 'o'
//    and


void	Server::Mode(int index, int id)
{
	if (commands.size() != 6)
	{
		clients[id].print("MODE: there are more or less arguman\n");
		return;
	}
	if (commands[index + 1][0] != '+' || commands[index + 1][0] != '-')
	{
		clients[id].print("MODE: there is no '+' or '-' in the first index\n");
		return;
	}
	for (size_t i = 0; i < commands.size(); i++)
	{
		
	}
	
	
}
