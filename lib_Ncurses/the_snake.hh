//
// the_snake.hh for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 16:33:48 2015 Aurélie LAO
// Last update Thu Apr  2 16:37:00 2015 Aurélie LAO
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

enum	eDirection
{
  Up = 0,
  Down,
  Right,
  Left
};

class		Snake
{
public:
  std::list<int>	_table;
  int			_x_max;
  int			_y_max;
  int			_x_eat;
  int			_y_eat;
  eDirection		_dir;  
  bool			_is_alive;
  bool			_have_meal;

public:
  Snake(int x, int y);
  ~Snake();
  void	turn_left();
  void	turn_right();
  void	go_up();
  void	go_down();
  void	go_continu();
  bool	check_can_eat();  
};

#endif
