//
// the_window.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 15:59:55 2015 Aurélie LAO
// Last update Sun Apr  5 17:51:30 2015 Aurélie LAO
//

#include "../header/the_snake.hh"
#include <stdlib.h>

Snake::Snake(int x, int y)
{
  this->_table.push_back(x / 2);
  this->_table.push_back(y / 2);
  this->_table.push_back(x / 2);
  this->_table.push_back((y / 2) - 1);
  this->_table.push_back(x / 2);
  this->_table.push_back((y / 2) - 2);

  this->_x_max = x;
  this->_y_max = y;
  while ((this->_x_eat = rand() % x) == 0 || this->_x_eat == (x / 2))
    rand();
  while ((this->_y_eat = rand() % y) == 0 ||
	 this->_y_eat == (y / 2) ||
	 this->_y_eat == (y / 2 - 1) ||
	 this->_y_eat == (y / 2 - 2))
    rand();
  this->_is_alive = true;
  this->_have_meal = false;
  this->_dir = Up;
}

Snake::~Snake()
{
}

void	Snake::turn_left()
{
  int	x;
  int	y;

  this->_dir = Left;
  if (this->_have_meal == 0)
    {
      this->_table.pop_back();
      this->_table.pop_back();
    }
  else
    this->_have_meal = this->_have_meal - 1;
  x = this->_table.front();
  this->_table.pop_front();
  y =  this->_table.front();
  this->_table.pop_front();
  this->_table.push_front(y);
  this->_table.push_front(x);
  this->_table.push_front(y);
  if (x - 1 <= 0)
    this->_is_alive = false;
  this->_table.push_front(x - 1);
}

void	Snake::turn_right()
{
  int	x;
  int	y;

  this->_dir = Right;
  if (this->_have_meal == 0)
    {
      this->_table.pop_back();
      this->_table.pop_back();
    }
  else
    this->_have_meal = this->_have_meal - 1;
  x = this->_table.front();
  this->_table.pop_front();
  y =  this->_table.front();
  this->_table.pop_front();
  this->_table.push_front(y);
  this->_table.push_front(x);
  this->_table.push_front(y);
  if (x + 1 >= this->_x_max)
    this->_is_alive = false;
  this->_table.push_front(x + 1);
}

void	Snake::go_up()
{
  int	x;
  int	y;

  this->_dir = Up;
  if (this->_have_meal == 0)
    {
      this->_table.pop_back();
      this->_table.pop_back();
    }
  else
    this->_have_meal = this->_have_meal - 1;
  x =  this->_table.front();
  this->_table.pop_front();
  y = this->_table.front();
  this->_table.pop_front();
  this->_table.push_front(y);
  this->_table.push_front(x);
  if (y + 1 >= this->_y_max)
    this->_is_alive = false;
  this->_table.push_front(y + 1);
  this->_table.push_front(x);
}

void	Snake::go_down()
{
  int	x;
  int	y;

  this->_dir = Down;
  if (this->_have_meal == 0)
    {
      this->_table.pop_back();
      this->_table.pop_back();
    }
  else
    this->_have_meal = this->_have_meal - 1;
  x = this->_table.front();
  this->_table.pop_front();
  y =  this->_table.front();
  this->_table.pop_front();
  this->_table.push_front(y);
  this->_table.push_front(x);
  if (y - 1 <= 0)
    this->_is_alive = false;
  this->_table.push_front(y - 1);
  this->_table.push_front(x);
}

void	Snake::go_continu()
{
  switch (this->_dir)
    {
    case Up:
      go_up();
      break;
    case Down:
      go_down();
      break;
    case Right:
      turn_right();
      break;
    case Left:
      turn_left();
      break;
    default:
      break;
    }
}

bool	Snake::check_is_alive()
{
  int	first_x;
  int	first_y;

  first_x = this->_table.front();
  this->_table.pop_front();
  first_y = this->_table.front();
  this->_table.pop_front();
  if (first_x == 0 || first_x == this->_x_max ||
      first_y == 0 || first_y == this->_y_max)
    {
      this->_is_alive = false;
      this->_table.push_front(first_y);
      this->_table.push_front(first_x);
      return (false);
    }
  for (std::list<int>::iterator it = this->_table.begin(); it != this->_table.end(); it++)
    {
      if (first_x == *it)
	{
	  ++it;
	  if (first_y == *it)
	    {
	      this->_table.push_front(first_y);
	      this->_table.push_front(first_x);
	      this->_is_alive = false;
	      return (false);
	    }
	  --it;
	}
      ++it;
    }
  this->_table.push_front(first_y);
  this->_table.push_front(first_x);
  return (true);
}

bool	Snake::check_can_eat()
{
  std::list<int>::iterator it = this->_table.begin();
  int	count = 0;

  while (it != this->_table.end())
    {
      if (*it == this->_x_eat)
	++count;
      ++it;
      if (count != 0 && *it == this->_y_eat)
	{
	  this->_x_eat = this->_table.back();
	  this->_table.pop_back();
	  this->_y_eat = this->_table.back();
	  this->_table.push_back(this->_y_eat);
	  this->_have_meal = 2;
	  return (true);
	}
      else if (it == this->_table.end())
	{
	  this->_have_meal = 2;
	  return (false);
	}
      ++it;
    }
  this->_have_meal = 0;
  return (false);
}
