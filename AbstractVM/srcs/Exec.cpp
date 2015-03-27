#include <iostream>
#include "../headers/Exception.hh"
#include "../headers/Exec.hh"

Exec::Exec()
{
  this->_stack = new Stack();
}

Exec::~Exec()
{
  delete this->_stack;
}

void	Exec::avm_exec(std::stringstream &content)
{
  std::list<std::string>	cmd;
  std::string			line;

  while (getline(content, line))
    {
      if (line[0] && line[0] != ';')
	{
	  cmd = this->_parser.avm_lexer(line);
	  this->_parser.avm_parser(cmd);
	  this->execute(cmd);
	}
      if (this->_stack->exitCmd == 1)
	break;
    }
  this->resetStack();
  if (this->_stack->exitCmd == 0)
    throw myException("There is no exit in this file");
  return;
}

void	Exec::resetStack()
{
  delete this->_stack;
  this->_stack = new Stack();
}

void	Exec::execute(std::list<std::string> &cmd)
{
  std::list<std::string>::iterator	it = cmd.begin();
  std::string	sInst[9] = {"dump", "print", "exit", "pop",
			    "add", "sub", "mul", "div", "mod"};
  fnPtr		sPtr[9] = {&Stack::dump, &Stack::print, &Stack::exit,
			   &Stack::pop, &Stack::add, &Stack::sub,
			   &Stack::mul, &Stack::div, &Stack::mod};
  std::string	cInst[2] = {"push", "assert"};
  fnCptr	cPtr[2] = {&Stack::push, &Stack::assert};
  int		count = 0;
  std::string	cmdInst = *it;
  std::string	cmdType;
  std::string	cmdValue;

  if (cmd.size() == 1)
    {
      while (count < 9)
	{
	  if (sInst[count] == cmdInst)
	    {
	      (this->_stack->*sPtr[count])();
	      return;
	    }
	  ++count;
	}
    }
  else if (cmd.size() == 3)
    {
      cmdType = *(++it);
      cmdValue = *(++it);
      while (count < 2)
	{
	  if (cInst[count] == cmdInst)
	    {
	      (this->_stack->*cPtr[count])(cmdValue,
					   this->_parser.typeValue(cmdType));
	      return;
	    }
	  ++count;
	}
    }

}
