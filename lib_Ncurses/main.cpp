//
// main.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 17:32:56 2015 Aurélie LAO
// Last update Sun Apr  5 19:25:28 2015 Aurélie LAO
//

#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "../header/the_snake.hh"
#include "../header/my_exception.hh"
#include <sstream>

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

int		main(int ac, char **av)
{
  int		x;
  int		y;

  try
    {
      if (ac != 4)
	throw My_exception(0, "Not enough arguments", "Usage: ./snake [width] [height] [librairy]");
      y = my_totoi(av[2]);
      x = my_totoi(av[1]);
      srand(time(0));
      std::cout << "ARGUMENTS = " << x << " - " << y << std::endl;
      Snake	s(x, y);
      std::cout << "test";
      try
	{
	  if (strcmp(av[3], "Ncurses") == 0)
	    go_Ncurses(&s);
	  else
	    throw My_exception(0, "Wrong librairy", "Choose Ncurses or []");
	}
      catch (std::exception &e)
	{
	  endCurses();
	  std::cerr << e.what() << std::endl;
	  return -1;
	}
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      return -1;
    }

  return 0;
}
