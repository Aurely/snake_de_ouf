//
// main.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 17:32:56 2015 Aurélie LAO
// Last update Wed Apr  1 17:42:22 2015 Aurélie LAO
//

#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include "the_snake.hh"
#include "my_exception.hh"

void		go_Ncurses(Snaaake *s)
{
}

int		main(int ac, char **av)
{
  int		x;
  int		y;

  try
    {
      if (ac != 4)
	throw My_exception(0, "Not enough arguments", "Usage: ./snake [weight] [height] [librairy]");
      y = atoi(av[2]); //A CHANGER
      x = atoi(av[1]); //A CHANGER
      std::cout << x << " - " << y << std::endl;
      Snaaake	s(x, y);
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
