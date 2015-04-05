//
// IGraphic.hpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf/src
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sun Apr  5 10:21:22 2015 Trotier Marie
// Last update Sun Apr  5 12:44:34 2015 Trotier Marie
//

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <vector>
#include "the_snake.hh"

class IGraphic
{
public:
  IGraphic(){}
  virtual	~IGraphic() {}

  virtual int	wait() = 0;
  virtual void	show_snake(std::vector<coord *> *) = 0;
  virtual int	init_window() = 0;
  virtual int	getsize_y() = 0;
  virtual int	getsize_x() = 0;
};

#endif
