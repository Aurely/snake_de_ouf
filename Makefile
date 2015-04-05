##
## Makefile for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Thu Apr  2 14:29:28 2015 Aurélie LAO
## Last update Sun Apr  5 19:29:50 2015 Aurélie LAO
##

CC		=	g++
RM		=	rm -f

BASE_SRCS	=	./src/main.cpp  \
			./src/my_exception.cpp \
			./src/the_snake.cpp \
			./src/moves.cpp \
##			./lib_NDK/NDKlib.cpp

BASE_OBJS	=	$(BASE_SRCS:.cpp=.o)
BASE_NAME	=	nibbler

SDL_SRCS	=	./lib_SDL/SDLlib.cpp
SDL_OBJS	=	$(SDL_SRCS:.cpp=.o)
SDL_NAME	=	lib_SDL.so

NDK_SRCS	=	./lib_NDK/NDKlib.cpp
NDK_OBJS	=	$(NDK_SRCS:.cpp=.o)
NDK_NAME	=	lib_NDK.so

CPPFLAGS  	=       -W -Wall -Wextra

all:			$(BASE_NAME)

$(BASE_NAME):		$(BASE_OBJS) $(SDL_OBJS)
			$(CC) -o $(BASE_NAME) $(BASE_OBJS) $(SDL_OBJS) $(CPPFLAGS) -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf -lncurses

# all:			$(BASE_NAME) $(SDL_NAME)

# $(BASE_NAME):		$(BASE_OBJS)
# 			$(CC) -o $(BASE_NAME) $(BASE_OBJS) $(CPPFLAGS)

# $(SDL_NAME):		$(SDL_OBJS)
# 			$(CC) -fPIC -c -o $(SDL_OBJS) $(SDL_SRCS)
# 			$(CC) -shared -o $(SDL_NAME) $(SDL_OBJS) -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf

# $(NDK_NAME):		$(NDK_OBJS)
# 			$(CC) -fPIC -c -o $(NDK_OBJS) $(NDK_SRCS)
# 			$(CC) -shared -o $(NDK_NAME) $(NDK_OBJS) -lncurses

clean:
			$(RM) $(SDL_OBJS)
			$(RM) $(BASE_OBJS)

fclean:			clean
			$(RM) $(BASE_NAME)
			$(RM) $(SDL_NAME)

re:			fclean all

.PHONY:			all clean fclean re
