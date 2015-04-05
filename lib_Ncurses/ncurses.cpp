//
// ncurses.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Fri Apr  3 15:14:38 2015 Aurélie LAO
// Last update Sun Apr  5 16:42:56 2015 Aurélie LAO
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
  printw("\n\n\n                %s\n", "END");
  printw("\n%s\n", "Nibbler by Marie TROTIER & Aurelie LAO");
  printw("\n\n\n       %s\n", "Press Enter to exit");
}

void	print_stat(Snake *s)
{
  printw("%s\n", "List =");
  for (std::list<int>::iterator it = s->_table.begin(); it != s->_table.end(); it++)
    printw("%d\n", *it);
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
	    case 65: //UP
	      if (s->_dir != Down)
		{
		  s->go_up();
		  if (s->check_is_alive() == false)
		    print_end();
		  else
		    {
		      s->check_can_eat();
		      print_map(s);
		      print_stat(s);
		    }
		}
	      else
		print_map(s);
	      break;
	    case 66: //DOWN
	      if (s->_dir != Up)
		{
		  s->go_down();
		  if (s->check_is_alive() == false)
		    print_end();
		  else
		    {
		      s->check_can_eat();
		      print_map(s);
		      print_stat(s);
		    }
		}
	      else
		print_map(s);
	      break;
	    case 67: //RIGHT
	      if (s->_dir != Left)
		{
		  s->turn_right();
		  if (s->check_is_alive() == false)
		    print_end();
		  else
		    {
		      s->check_can_eat();
		      print_map(s);
		      print_stat(s);
		    }
		}
	      else
		print_map(s);
	      break;
	    case 68: //LEFT
	      if (s->_dir != Right)
		{
		  s->turn_left();
		  if (s->check_is_alive() == false)
		    print_end();
		  else
		    {
		      s->check_can_eat();
		      print_map(s);
		      print_stat(s);
		    }
		}
	      else
		print_map(s);
	      break;
	    default:
	      break;
	    }
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
