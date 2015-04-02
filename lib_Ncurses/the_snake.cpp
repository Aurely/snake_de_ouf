//
// the_window.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 15:59:55 2015 Aurélie LAO
// Last update Thu Apr  2 14:31:12 2015 Aurélie LAO
//

#include "the_snake.hh"
#include <stdlib.h>

Snake::Snake(int x, int y)
{
  this->table.push_back(x / 2);
  this->table.push_back(y / 2);
  this->table.push_back(x / 2);
  this->table.push_back((y / 2) - 1);
  this->table.push_back(x / 2);
  this->table.push_back((y / 2) - 2);

  this->x_max = x;
  this->y_max = y;
  this->x_eat = rand() % x;
  this->y_eat = rand() % y;
  this->is_alive = true;
  this->have_meal = false;
}

Snake::~Snake()
{
}

void	Snake::turn_left()
{
}

void	Snake::turn_right()
{
}

void	Snake::go_up()
{
}

bool	Snake::check_can_eat()
{
  return (false);
}
