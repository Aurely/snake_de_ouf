//
// SDLlib.cpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf/lib_SDL
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sat Apr  4 18:52:32 2015 Trotier Marie
// Last update Sun Apr  5 13:03:26 2015 Trotier Marie
//

#include <sstream>
#include <ostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>  
#include "SDLlib.hpp"

MySDL::MySDL(int x, int y)
{
  this->_x = x;
  this->_y = y;
}

MySDL::~MySDL()
{
  SDL_Quit();
}

//on sait pas encore quoi en faire ??
int    MySDL::wait()
{
  SDL_Event     event;

  SDL_WaitEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      return (-1);
    case SDL_KEYDOWN:
      {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  return (-1);
	if (event.key.keysym.sym == SDLK_UP)
	  return (1);
	if (event.key.keysym.sym == SDLK_DOWN)
	  return (2);
	if (event.key.keysym.sym == SDLK_RIGHT)
	  return (3);
	if (event.key.keysym.sym == SDLK_LEFT)
	  return (4);
      }
      return (0);
    }
  return (0);
}

//affichage du snake dans la fenetre
void    MySDL::show_snake(std::vector<coord *>* snake)
{
  SDL_Rect      pos;

  SDL_FillRect(this->screen, NULL, 0);
  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      pos.x = pos((*it)->x);
      pos.y = pos((*it)->y);
      if ((it) == snake->begin())
      	SDL_BlitSurface(this->head, NULL, this->screen, &pos);
      else
	SDL_BlitSurface(this->body, NULL, this->screen, &pos);
    }
  SDL_Flip(this->screen);
}

  //initialisation
int	MySDL::init_window()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  if ((this->screen = SDL_SetVideoMode(20 * this->_x, 20 * this->_y, 32, SDL_HWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("Nibbler", NULL);
  // //charge le sprite pour le snake
  if ((this->head = IMG_Load("./lib_SDL/head.jpg")) == NULL ||
      (this->body = IMG_Load("./lib_SDL/body.jpg")) == NULL ||
      (this->food = IMG_Load("./lib_SDL/food.jpg")) == NULL)
    return (-1);

  SDL_Flip(screen);
  return(0);
}

int	MySDL::getsize_y()
{
  return (this->_y);
}

int	MySDL::getsize_x()
{
  return (this->_x);
}
