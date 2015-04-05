//
// moves.cpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sun Apr  5 11:38:40 2015 Trotier Marie
// Last update Sun Apr  5 17:50:02 2015 Trotier Marie
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

static int	check_obstacle(std::vector<coord *>*snake)
{
  for (std::vector<coord *>::const_iterator op = snake->begin(); op != snake->end(); op++)
    {
      if (((((*op)->x == (*(snake->begin()))->x) && ((*op)->y == (*(snake->begin()))->y)))
	  && op != snake->begin())
	return (-1);
    }
  return (0);
}

static int	move_snake(std::vector<coord *> *snake, int dir)
{
  coord	prev;
  coord	tmp;

  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
  	{
  	  prev.x = (*it)->x;
  	  prev.y = (*it)->y;
	  if (dir == UP)
	    {
	      if ((*it)->y <= 0)
		return (-1);
	      (*it)->y = (*it)->y - 1;
	    }
	  if (dir == LEFT)
	    {
	      if ((*it)->x <= 0)
		return (-1);
	      (*it)->x = (*it)->x - 1;
	    }
  	}
      else
  	{
  	  tmp.x = (*it)->x;
  	  tmp.y = (*it)->y;
  	  (*it)->x = prev.x;
  	  (*it)->y = prev.y;
  	  prev.x = tmp.x;
  	  prev.y = tmp.y;
  	}
    }
  return (0);
}

static int	move_snake2(std::vector<coord *> *snake, int dir, IGraphic *gui)
{
  coord	prev;
  coord	tmp;

  for (std::vector<coord *>::const_iterator it = snake->begin(); it != snake->end(); it++)
    {
      if (it == snake->begin())
  	{
  	  prev.x = (*it)->x;
  	  prev.y = (*it)->y;
	  if (dir == DOWN)
	    {
	      if ((*it)->y + 1 == gui->getsize_y())
		return (-1);
	      (*it)->y = (*it)->y + 1;
	    }
	  if (dir == RIGHT)
	    {
	      if ((*it)->x + 1 == gui->getsize_x())
		return (-1);
	      (*it)->x = (*it)->x + 1;
	    }
  	}
      else
  	{
  	  tmp.x = (*it)->x;
  	  tmp.y = (*it)->y;
  	  (*it)->x = prev.x;
  	  (*it)->y = prev.y;
  	  prev.x = tmp.x;
  	  prev.y = tmp.y;
  	}
    }
  return (0);
}

int	move_down(int *t, std::vector<coord *> *snake, IGraphic *gui, int dir)
{
  *t = 1;
  if (dir == UP)
    return (0);
  *t = 0;
  if (move_snake2(snake, DOWN, gui) == -1)
    return (-1);
  return (check_obstacle(snake));
}

int	move_right(int *t, std::vector<coord *> *snake, IGraphic *gui, int dir)
{
  *t = 1;
  if (dir == LEFT)
    return (0);
  *t = 0;
  if (move_snake2(snake, RIGHT, gui) == -1)
    return (-1);
  return (check_obstacle(snake));
}

int	move_left(int *t, std::vector<coord *> *snake, int dir)
{
  *t = 1;
  if (dir == RIGHT)
    return (0);
  *t = 0;
  if (move_snake(snake, LEFT) == -1)
    return (-1);
  return (check_obstacle(snake));
}

int	move_up(int *t, std::vector<coord *> *snake, int dir)
{
  *t = 1;
  if (dir == DOWN)
    return (0);
  *t = 0;
  if (move_snake(snake, UP) == -1)
    return (-1);
  return (check_obstacle(snake));
}
