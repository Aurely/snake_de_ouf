##
## Makefile for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Thu Apr  2 14:29:28 2015 Aurélie LAO
## Last update Thu Apr  2 14:32:06 2015 Aurélie LAO
##

CC	=	g++

RM	=	rm -f

SRC	=	main.cpp \
		the_snake.cpp \
		my_exception.cpp

NAME	=	snake

all	:	$(NAME)

$(NAME)	:
		$(CC) -o $(NAME) $(SRC) -lncurses -Wall -Wextra -Werror

fclean	:
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all fclean re
