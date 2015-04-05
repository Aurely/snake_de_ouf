//
// main.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 17:32:56 2015 Aurélie LAO
// Last update Sun Apr  5 13:04:30 2015 Trotier Marie
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

  while (cond == 1)
    {
      gui->show_snake(snake);
      key = gui->wait();
      if (key == -1)
      	cond = 0;
      if (key == 1 && move_up(snake, gui) == -1)
	cond = 0;
      if (key == 2 && move_down(snake, gui) == -1)
	cond = 0;
      if (key == 3 && move_right(snake, gui) == -1)
	cond = 0;
      if (key == 4 && move_left(snake, gui) == -1)
	cond = 0;
    }
}

int		main(int ac, char **av)
{
  int		x;
  int		y;

  try
    {
      if (ac != 4)
	throw My_exception(0, "Not enough arguments", "Usage: ./snake [weight] [height] [librairy]");
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
  IGraphic	*gui;

  //crées la bonne gui
  gui = new MySDL(x, y);

  //init the snake
  std::vector<coord *> snake;
  coord	*point = new coord;
  coord	*point_body = new coord;
  coord	*point_body2 = new coord;

  point->x = 2;
  point->y = 0;
  snake.push_back(point);
  point_body->x = 1;
  point_body->y = 0;
  snake.push_back(point_body);
  point_body2->x = 0;
  point_body2->y = 0;
  snake.push_back(point_body2);

  gui->init_window();
  launch_game(&snake, gui);
  delete gui;
  //delete tous les points du snake
  return 0;
}
