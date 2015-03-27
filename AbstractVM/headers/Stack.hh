#ifndef STACK_HH_
# define STACK_HH_

# include <list>
# include "IOperand.hh"
# include "Operand.hh"

class Stack;
typedef IOperand *(Stack::*m_fptr)(const std::string&);

class	Stack
{
private:
  std::list<IOperand*>	_stack;

  IOperand * createInt8(const std::string &value);
  IOperand * createInt16(const std::string &value);
  IOperand * createInt32(const std::string &value);
  IOperand * createFloat(const std::string &value);
  IOperand * createDouble(const std::string &value);
public:
  bool			exitCmd;
  Stack();
  ~Stack();

  IOperand * createOperand(eOperandType type, const std::string & value);

  void push(const std::string& value, const eOperandType &type);
  void assert(const std::string& value, const eOperandType &type);

  void dump();
  void exit();
  void print();
  void pop();

  IOperand *getTop();
  void add();
  void sub();
  void mul();
  void div();
  void mod();
};
#endif /* !STACK_HH_ */
