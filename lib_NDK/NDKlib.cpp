//
// NDKlib.cpp for  in /home/trotie_m/training/snake_de_ouf/snake_de_ouf/lib_NDK
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Sun Apr  5 17:52:19 2015 Trotier Marie
// Last update Sun Apr  5 18:27:26 2015 Trotier Marie
//

#include <sstream>
#include <ostream>
#include "NDKlib.hpp"

MyNDK::MyNDK(int x, int y)
{
  this->_x = x;
  this->_y = y;
}

MyNDK::~MyNDK()
{
  //reinit les statuts de base
}

int	MyNDK::wait()
{
  // return la touche
  return (0);
}

void	MyNDK::show_snake(__attribute__((unused))std::vector<coord *>*snake)
{
  // nettoie l'écran
  // affiche le snake
  // reactualise
}

int	MyNDK::init_window()
{
  // init ncurses et la fenetre
  return (0);
}

int	MyNDK::getsize_y()
{
  return (this->_y);
}

int	MyNDK::getsize_x()
{
  return (this->_x);
}
