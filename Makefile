NAME	= IRC

SOURCES	= server.cpp Parse.cpp User.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC		= c++
FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

clean:
	rm -f *.o
	rm -rf .vscode

fclean: clean
	rm -f $(NAME)

re:	fclean all