CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ircserv

SRC = Channel/Channel.cpp Client/Client.cpp Server/Server.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)
re: clean all

.PHONY: clean all re