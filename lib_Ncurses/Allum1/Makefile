##
## Makefile for Allum1 in /home/lao_e/rendu/Allum1
## 
## Made by lao_e
## Login   <lao_e@epitech.net>
## 
## Started on  Tue Feb  4 15:17:24 2014 lao_e
## Last update Sat Feb 15 14:12:08 2014 lao_e
##

CC	=	gcc

RM	=	rm -f

SRC	=	allum.c			\
		fonctions_annexes.c	\
		modif_term.c		\
		allum2.c		\
		allum3.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	allum1

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(SRC) -lncurses

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	clean all

.PHONY	:	all clean fclean re
