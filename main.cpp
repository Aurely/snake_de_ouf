//
// main.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 17:32:56 2015 Aurélie LAO
// Last update Thu Apr  2 18:11:58 2015 Trotier Marie
//

#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "the_snake.hh"
#include "my_exception.hh"
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

void		go_Ncurses(Snake *s)
{
  check_status(s);
  s->check_can_eat();
  check_status(s);
}

int		main(int ac, char **av)
{
  int		x;
  int		y;

  try
    {
      if (ac != 4)
	throw My_exception(0, "Not enough arguments", "Usage: ./snake [weight] [height] [librairy]");
      y = my_totoi(av[2]); //A CHANGER
      x = my_totoi(av[1]); //A CHANGER
      srand(time(0));
      std::cout << "ARGUMENTS = " << x << " - " << y << std::endl;
      Snake	s(x, y);
      if (strcmp(av[3], "Ncurses") == 0)
	go_Ncurses(&s);
      else
	throw My_exception(0, "Wrong librairy", "Choose Ncurses or []");
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      return -1;
    }
  return 0;
}
