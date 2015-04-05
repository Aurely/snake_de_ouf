CC	=	g++

SRC	=	ncurses.cpp \
		main.cpp \
		the_snake.cpp \
		my_exception.cpp

NAME	=	snake

all	:	$(NAME)

$(NAME)	:
		$(CC) -o $(NAME) $(SRC) -lncurses

fclean	:
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all fclean re
