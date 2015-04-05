//
// moves.cpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sun Apr  5 11:38:40 2015 Trotier Marie
// Last update Sun Apr  5 13:21:57 2015 Trotier Marie
//

#include <vector>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "../header/the_snake.hh"
#include "../header/my_exception.hh"
#include "../header/IGraphic.hpp"
#include "../lib_SDL/SDLlib.hpp"

int	move_up(std::vector<coord *> *snake, __attribute__((unused))IGraphic *gui)
{
  //check si le mouvement est possible (collision ? ect)
  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
	{
	  (*it)->y = (*it)->y - 1;
	  if ((*it)->y < 0)
	    return (-1);
	}
      else
	{
	  //va la ou etait le précedent
	}
    }
  //check si head est pas rentré dans le body du snake
  //décaler toutes les positions du corps avec leur element précedent
  return (0);
}

int	move_down(std::vector<coord *> *snake, IGraphic *gui)
{
  //check si le mouvement est possible (collision ? ect)
  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
	{

	  (*it)->y = (*it)->y + 1;
	  if ((*it)->y == gui->getsize_y())
	    return (-1);
	}
      else
	{
	  //va la ou etait le précedent
	}
    }
  //check si head est pas rentré dans le body du snake
  //décaler toutes les positions du corps avec leur element précedent
  return (0);
}

int	move_left(std::vector<coord *> *snake, __attribute__((unused))IGraphic *gui)
{
  //check si le mouvement est possible (collision ? ect)
  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
	{

      (*it)->x = (*it)->x - 1;
      if ((*it)->x < 0)
	return (-1);
	}
      else
	{
	  //va la ou etait le précedent
	}


    }
  //check si head est pas rentré dans le body du snake
  //décaler toutes les positions du corps avec leur element précedent
  return (0);
}

int	move_right(std::vector<coord *> *snake, IGraphic *gui)
{
  //check si le mouvement est possible (collision ? ect)
  coord	prev;

  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
	{
	  prev.x = (*it)->x;
	  prev.y = (*it)->y;
	  (*it)->x = (*it)->x + 1;
	  if ((*it)->x == gui->getsize_x())
	    return (-1);
	}
      else
	{
	  // (*it)->x = prev.x;
	  // (*it)->y = prev.y;
	  //va la ou etait le précedent
	}
      prev.x = (*it)->x;
      prev.y = (*it)->y;
      std::cout << prev.x << ";" << prev.y <<  std::endl;
    }
  //check si head est pas rentré dans le body du snake
  //décaler toutes les positions du corps avec leur element précedent
  return (0);
}
