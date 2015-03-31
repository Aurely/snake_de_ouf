//
// my_print.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Tue Mar 31 10:47:51 2015 Aurélie LAO
// Last update Tue Mar 31 12:10:09 2015 Aurélie LAO
//

#include <ncurses/curses.h>
#include "my_exception.hh"
#include <iostream>
#include <cstring>
#include <unistd.h>

bool curses_started = false;

void endCurses()
{
  if (curses_started && !isendwin())
    endwin();
}


void startCurses()
{
  if (curses_started)
    refresh();
  else
    {
      initscr();
      cbreak();
      noecho();
      intrflush(stdscr, false);
      keypad(stdscr, true);
      curses_started = true;
    }
}

void	go_Ncurses()
{
  std::cout << "Librairie : Ncurses" << std::endl;
  startCurses();
  sleep(2);
  endCurses();
}

int	main(int ac, char **av)
{
  try
    {
      if (ac != 2)
	throw My_exception(0, "Not enough arguments", "Please enter a library");
      if (strcmp(av[1], "Ncurses") == 0)
	go_Ncurses();
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
