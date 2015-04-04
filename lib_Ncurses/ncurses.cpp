//
// ncurses.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Fri Apr  3 15:14:38 2015 Aurélie LAO
// Last update Sat Apr  4 19:13:58 2015 Aurélie LAO
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

void		print_snake(int y, Snake *s)
{
  int		x = 1;
  std::string		str;

  str = "|";
  while (x < s->_x_max - 1)
    {
      if (check_y(y, s) == true)
	{
	  if (check_x(x, s) == true)
	    str = str + "o";
	  else
	    str = str + " ";
	}
      else if (y == s->_y_eat)
	{
	  if (x == s->_x_eat)
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
}

void		print_map(Snake *s)
{
  int		x = s->_x_max;
  int		y = s->_y_max - 1;
  //  int		y = s->_y_max - 2;
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
      print_snake(y, s);
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

void	print_end()
{
  printw("\n\n\n       %s\n", "END");
}

void	my_print(Snake *s)
{
  int	key;

  print_map(s);
  while ((key = getch()) != 10)
    {
      clear();
      if (s->check_is_alive() != false && s->_is_alive != false)
      	{
	  switch (key)
	    {
	    case 65:
	      s->go_up();
	      //printw("%s\n", "touche UP");
	      break;
	    case 66:
	      s->go_down();
	      //printw("%s\n", "touche DOWN");
	      break;
	    case 67:
	      s->turn_right();
	      //printw("%s\n", "touche RIGHT");
	      break;
	    case 68:
	      s->turn_left();
	      //printw("%s\n", "touche LEFT");
	      break;
	    default:
	      break;
	    }
	  print_map(s);
	}
      else
	print_end();
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
