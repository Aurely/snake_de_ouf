NAME		= avm

SRCS		= $(wildcard srcs/*.cpp)

OBJS		= $(SRCS:.cpp=.o)

CPPFLAGS	+= -Wall -Wextra -Werror

CC		= g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
