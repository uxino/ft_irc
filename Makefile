NAME	= IRC

SOURCES	= server.cpp Parse.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)
	rm -rf *.o

.cpp.o:
	$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all