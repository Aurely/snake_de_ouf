//
// SDLlib.hpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf/lib_SDL
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sat Apr  4 18:51:18 2015 Trotier Marie
// Last update Sun Apr  5 12:45:13 2015 Trotier Marie
//

#ifndef SDLLIB_HPP_
# define SDLLIB_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../header/IGraphic.hpp"

# define pos(x) (x * 20)

class   MySDL : public IGraphic
{
private:
  SDL_Surface	*screen;
  SDL_Surface	*head;
  SDL_Surface	*body;
  SDL_Surface	*food;
  int	_x;
  int	_y;

public:
  MySDL(int x, int y);
  ~MySDL();

  int	init_window();
  int	wait();
  void	show_snake(std::vector<coord *>*);
  int	getsize_y();
  int	getsize_x();
};

#endif
