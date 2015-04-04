//
// ncurses.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Fri Apr  3 15:14:38 2015 Aurélie LAO
// Last update Sat Apr  4 00:13:26 2015 Aurélie LAO
//

#include <ncurses/curses.h>
#include <unistd.h>
#include "../header/the_snake.hh"
#include "../header/my_exception.hh"
#include <string>

bool curses_started = false;

bool		check_y(int y, Snake *s)
{
  std::list<int>::iterator it = s->_table.begin();

  while (it != s->_table.end())
    {
      ++it;
      if ((y != s->_y_max) && (y == *it))
	return (true);
      ++it;
    }
  return (false);
}

bool		check_x(int x,Snake *s)
{
  std::list<int>::iterator it = s->_table.begin();

  while (it != s->_table.end())
    {
      if ((x != s->_x_max) && (x == *it))
	return (true);
      ++it;
      ++it;
    }
  return (false);
}

void		print_snake(Snake *s)
{
  int		x = 1;
  static int	y = 1;
  std::string		str;

  str = "|";
  while (x < s->_x_max - 1)
    {
      if (check_y(y, s) == true)
	{
	  if (check_x(x, s) == true)
	    str = str + "*";
	  else
	    str = str + " ";
	}
      else
	str = str + " ";
      ++x;
    }
  str = str + "|";
  printw("%s\n", str.c_str());
  ++y;
}

void		print_map(Snake *s)
{
  int		x = s->_x_max;
  int		y = s->_y_max - 2;
  std::string	first_str;

  while (x > 0)
    {
      first_str = first_str + "-";
      --x;
    }
  x = s->_x_max - 1;
  printw("%s\n", first_str.c_str());
  while (y > 0)
    {
      print_snake(s);
      --y;
    }
  printw("%s\n", first_str.c_str());
}

void	endCurses()
{
  if (curses_started && !isendwin())
    if (endwin() != OK)
      throw My_exception(1, "Close window failed");
}

void	startCurses()
{
  if (curses_started)
    {
      if (refresh() != OK)
	throw My_exception(1, "Refresh window failed");
    }
  else
    {
      curses_started = true;
      if (initscr() == NULL || cbreak() != 0 /*recup 1 seule touche*/|| noecho() != 0/*n'affiche pas la toucher pressée*/)
       	throw My_exception(1, "Initialisation Ncurses failed");
      curs_set(0);
    }
}

void	my_print(Snake *s)
{
  int	key;

  print_map(s);
  while ((key = getch()) != 10)
    {
      clear();
      print_map(s);
      switch (key)
	{
	case 65:
	  printw("%s\n", "touche UP");
	  break;
	case 66:
	  printw("%s\n", "touche DOWN");
	  break;
	case 67:
	  printw("%s\n", "touche RIGHT");
	  break;
	case 68:
	  printw("%s\n", "touche LEFT");
	  break;
	default:
	  break;
	}
    }
}
void		go_Ncurses(Snake *s)
{
  check_status(s);
  s->check_can_eat();
  startCurses();
  my_print(s);
  endCurses();
}
