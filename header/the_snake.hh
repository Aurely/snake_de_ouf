//
// the_snake.hh for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Wed Apr  1 16:33:48 2015 Aurélie LAO
// Last update Sun Apr  5 12:41:57 2015 Trotier Marie
//

#ifndef THE_SNAKE_HH_
# define THE_SNAKE_HH_

#include <vector>
#include <iostream>
#include <list>

class IGraphic;

typedef struct	coord
{
  int	x;
  int	y;
}	coord;

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
  int			_have_meal;

public:
  Snake(int x, int y);
  ~Snake();
  void	turn_left();
  void	turn_right();
  void	go_up();
  void	go_down();
  void	go_continu();
  bool	check_can_eat();  
  bool	check_is_alive();
};

int	my_totoi(char *str);
void	check_status(Snake *s);
void	go_Ncurses(Snake *s);
void	endCurses();

int	move_up(std::vector<coord *> *snake, IGraphic *gui);
int	move_down(std::vector<coord *> *snake, IGraphic *gui);
int	move_right(std::vector<coord *> *snake, IGraphic *gui);
int	move_left(std::vector<coord *> *snake, IGraphic *gui);

#endif
