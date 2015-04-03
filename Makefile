##
## Makefile for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Thu Apr  2 14:29:28 2015 Aurélie LAO
## Last update Fri Apr  3 15:25:45 2015 Aurélie LAO
##

CC	=	g++

RM	=	rm -f

SRC	=	./src/main.cpp \
		./src/the_snake.cpp \
		./src/my_exception.cpp \
		./lib_Ncurses/ncurses.cpp

NAME	=	snake

all	:	$(NAME)

$(NAME)	:
		$(CC) -o $(NAME) $(SRC) -lncurses -Wall -Wextra -Werror

fclean	:
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all fclean re
