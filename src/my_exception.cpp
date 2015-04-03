//
// my_exception.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Tue Mar 31 11:04:06 2015 Aurélie LAO
// Last update Fri Apr  3 15:24:51 2015 Aurélie LAO
//

#include <string>
#include "../header/my_exception.hh"

My_exception::My_exception(int code, std::string const &error, std::string const &solution) throw()
{
  switch (code)
    {
    case 0:
      this->_msgcode = "Main error";
      break;
    default:
      this->_msgcode = "Error";
    }
  this->_error = error;
  this->_solution = solution;
  this->_message = this->_msgcode + " : " + this->_error + ".\n  --> " + this->_solution + ".";
}

My_exception::~My_exception() throw()
{}

const char	*My_exception::what() const throw()
{
  return (this->_message.c_str());
}
