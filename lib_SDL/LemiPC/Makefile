##
## Makefile for  in /home/antune_r/rendu/PSU_2014_lemipc
## 
## Made by Romain Antunes
## Login   <antune_r@epitech.net>
## 
## Started on  Tue Mar  3 13:45:38 2015 Romain Antunes
## Last update Sun Mar  8 16:35:33 2015 Aurélie LAO
##

SRCS	=	lemipc.c \
		affi.c \
		gaming.c \
		is_eat.c \
		message.c \
		positioning.c \
		semaphore.c \
		shared_memory.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	lemipc

CC	=	cc -o $(NAME)

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Werror -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf -g

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
