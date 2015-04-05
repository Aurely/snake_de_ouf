//
// main.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 17:32:56 2015 Aurélie LAO
// Last update Sun Apr  5 19:25:24 2015 Aurélie LAO
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

int                     my_totoi(char *str)
{
  std::istringstream    stream((std::string(str)));
  int                   result;
  int                   i = 0;

  stream >> result;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        throw My_exception(0, "Wrong Arguments", "Usage: ./snake [weight] [height] [librairy]");
      i = i + 1;
    }
  if (result == 0)
    throw My_exception(0, "Wrong Arguments", "Usage: ./snake [weight] [height] [librairy]");    
  return (result);
}

void		check_status(Snake *s)
{
  std::cout << "List = ";
  for (std::list<int>::iterator it = s->_table.begin(); it != s->_table.end(); it++)
    std::cout << *it << ' ';
  std::cout << std::endl;
  std::cout << "x max -------- " << s->_x_max << std::endl;
  std::cout << "y max -------- " << s->_y_max << std::endl;
  std::cout << "x eat -------- " << s->_x_eat << std::endl;
  std::cout << "y eat -------- " << s->_y_eat << std::endl;
  std::cout << "alive -------- " << s->_is_alive << std::endl;
  std::cout << "mange ? ------ " << s->_have_meal << std::endl;
}

void		launch_game(std::vector<coord *> *snake, IGraphic *gui)
{
  int		cond = 1;
  int		key;
  int		old;
  int		marie;


  old = RIGHT;
  while (cond == 1)
    {
      marie = 0;
      gui->show_snake(snake);
      key = gui->wait();
      if (key == -1)
      	cond = 0;
      if (key == UP && move_up(&marie, snake, old) == -1)
	cond = 0;
      if (key == DOWN && move_down(&marie, snake, gui, old) == -1)
	cond = 0;
      if (key == RIGHT && move_right(&marie, snake, gui, old) == -1)
	cond = 0;
      if (key == LEFT && move_left(&marie, snake, old) == -1)
	cond = 0;
      if ((key == UP || key == DOWN || key == LEFT || key == RIGHT) && marie == 0)
	old = key;
    }
}

void		add_snake_part(std::vector<coord *> *snake, int x, int y)
{
  coord *point = new coord;

  point->x = x;
  point->y = y;
  snake->push_back(point);
}

int		main(int ac, char **av)
{
  int		x;
  int		y;
  std::vector<coord *> snake;

  try
    {
      if (ac != 4)
	throw My_exception(0, "Not enough arguments", "Usage: ./snake [width] [height] [librairy]");
      y = my_totoi(av[2]);
      x = my_totoi(av[1]);
      srand(time(0));
      Snake	s(x, y);
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      return -1;
    }
      try
	{
	  if (strcmp(av[3], "SDL") == 0)
	    {
	      IGraphic	*gui;
	      
	      //crées la bonne gui
	      gui = new MySDL(x, y);
	      // gui = new MyNDK(x, y);
	      
	      x = 3;
	      while (x >= 0)
		{
		  add_snake_part(&snake, x, 0);
		  x = x - 1;
		}
	      if (gui->init_window() == -1)
		return (-1);
	      launch_game(&snake, gui);
	    }
	  else if (strcmp(av[3], "Ncurses") == 0)
	    {
	      Snake s(x, y);

	      go_ncruses(&s);
	    }
	  else
	    throw My_exception(0, "Wrong librairy", "Choose Ncurses or []");
	  delete gui;
	}
      catch (std::exception &e)
	{
	  std::cerr << e.what() << std::endl;
	  return -1;
	}
    }
  return 0;
}
