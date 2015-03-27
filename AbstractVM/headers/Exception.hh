#ifndef EXCEPTION_HH_
# define EXCEPTION_HH_

# include <exception>
# include <iostream>

class	myException : public std::exception
{
private:
  std::string	_message;
public:
  myException(std::string const &message) throw();
  virtual ~myException() throw();
  virtual const char *what() const throw();
};

#endif /* !EXCEPTION_HH_ */
