//
// the_snake.hh for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 16:33:48 2015 Aurélie LAO
// Last update Thu Apr  2 14:26:30 2015 Aurélie LAO
//

#ifndef THE_SNAKE_HH_
# define THE_SNAKE_HH_

#include <iostream>
#include <list>

// EXEMPOULE:
   // y
   // --------------------
   // |                  |
   // |                  |
   // |                  |
   // |                  |
   // |        0         |
   // |        O         |
   // |        O         |
   // |                  |
   // |                  |
   // -------------------- x

class		Snake
{
public:
  std::list<int>	table;
  int			x_max;
  int			y_max;
  int			x_eat;
  int			y_eat;
  bool			is_alive;
  bool			have_meal;

public:
  Snake(int x, int y);
  ~Snake();
  void	turn_left();
  void	turn_right();
  void	go_up();
  bool	check_can_eat();  
};

#endif
