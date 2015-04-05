//
// NDKlib.hpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf/lib_NDK
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sun Apr  5 17:56:30 2015 Trotier Marie
// Last update Sun Apr  5 17:59:52 2015 Trotier Marie
//

#ifndef NDKLIB_HPP_                                                                          
# define NDKLIB_HPP_

// includes ncurses icix
#include "../header/IGraphic.hpp"

class   MyNDK : public IGraphic
{
private:
  int   _x;
  int   _y;

public:
  MyNDK(int x, int y);
  ~MyNDK();

  int   init_window();
  int   wait();
  void  show_snake(std::vector<coord *>*);
  int   getsize_y();
  int   getsize_x();
};

#endif

