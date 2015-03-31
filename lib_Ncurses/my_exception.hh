//
// my_exception.hh for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Tue Mar 31 11:05:58 2015 Aurélie LAO
// Last update Tue Mar 31 11:22:46 2015 Aurélie LAO
//

#ifndef MY_EXCEPTION_HH_
# define MY_EXCEPTION_HH_

# include <exception>
# include <iostream>

class	My_exception : public std::exception
{
private:
  int		_code;
  std::string	_msgcode;
  std::string	_error;
  std::string	_solution;
  std::string	_message;

public:
  My_exception(int i, std::string const &error, std::string const &solution) throw();
  virtual ~My_exception() throw();
  virtual const char *what() const throw();
};

#endif
