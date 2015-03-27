#ifndef EXEC_HH_
# define EXEC_HH_

# include <list>
# include <sstream>
# include "IOperand.hh"
# include "Parser.hh"
# include "Stack.hh"

class	Stack;
class	Parser;

typedef void (Stack::*fnCptr)(const std::string &value, const eOperandType &type);
typedef void (Stack::*fnPtr)();

class	Exec
{
private:
  Stack		*_stack;
public:
  Parser	_parser;

  Exec();

  ~Exec();

  void	avm_exec(std::stringstream &content);
  void	resetStack();
  void	execute(std::list<std::string> &cmd);
};
#endif /* !EXEC_HH_ */
