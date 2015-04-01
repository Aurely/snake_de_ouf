CC	=	g++

RM	=	rm -f

SRC	=	my_print.cpp \
		my_exception.cpp

NAME	=	test_exception

all	:	$(NAME)

$(NAME)	:
		$(CC) -o $(NAME) $(SRC) -lncurses -Wall -Wextra -Werror

fclean	:
		$(RM) $(NAME)

.PHONY	:	all fclean
