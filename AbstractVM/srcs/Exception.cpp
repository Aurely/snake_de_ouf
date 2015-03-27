#include <string>
#include "../headers/Exception.hh"

myException::myException(std::string const &message) throw()
{
  this->_message = message;
}

myException::~myException() throw() {}

const char	*myException::what() const throw()
{
  return (this->_message.c_str());
}
