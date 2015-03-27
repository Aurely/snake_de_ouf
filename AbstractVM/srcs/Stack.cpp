#include <iomanip>
#include <sstream>
#include <iostream>
#include "../headers/Exception.hh"
#include "../headers/Stack.hh"

Stack::Stack() {}

Stack::~Stack() {}

// PRIVATE CREATE

IOperand	*Stack::createInt8(const std::string &value)
{
  IOperand	*ret = new Operand<char>(value, Int8);
  return ret;
}

IOperand	*Stack::createInt16(const std::string &value)
{
  IOperand	*ret = new Operand<short int>(value, Int16);
  return ret;
}

IOperand	*Stack::createInt32(const std::string &value)
{
  IOperand	*ret = new Operand<int>(value, Int32);
  return ret;
}

IOperand	*Stack::createFloat(const std::string &value)
{
  IOperand	*ret = new Operand<float>(value, Float);
  return ret;
}

IOperand	*Stack::createDouble(const std::string &value)
{
  IOperand	*ret = new Operand<double>(value, Double);
  return ret;
}

// CREATE OPERAND

IOperand	*Stack::createOperand(eOperandType type, const std::string & value)
{
  m_fptr	typeTab[5] = {&Stack::createInt8, &Stack::createInt16,
			      &Stack::createInt32, &Stack::createFloat,
			      &Stack::createDouble};
  return (this->*typeTab[type])(value);
}

// INSTRUCTIONS

void	Stack::push(const std::string& value, const eOperandType &type)
{
  IOperand	*newOpe;

  newOpe = this->createOperand(type, value);
  this->_stack.push_front(newOpe);
}

void	Stack::assert(const std::string& value, const eOperandType &type)
{
  if (this->_stack.empty())
    throw myException("Assert fail : Empty stack");
  if (this->_stack.front()->toString() != value || this->_stack.front()->getType() != type)
    throw myException("Assert fail : incorrect value");
}

void	Stack::dump()
{
  for (std::list<IOperand*>::iterator it = this->_stack.begin();
       it != this->_stack.end(); ++it)
    std::cout << (*it)->toString() << std::endl;
}

void	Stack::exit()
{
  this->exitCmd = 1;
}

void	Stack::print()
{
  if (this->_stack.front()->getType() != 0)
    throw myException("Value is not a char");
  std::cout << this->_stack.front()->toString() << std::endl;
}

void	Stack::pop()
{
  if (this->_stack.empty())
    throw myException("Empty stack");
  else
    this->_stack.pop_front();
}

// OPERATIONS INST
IOperand	*Stack::getTop()
{
  IOperand	*ret;

  ret = this->_stack.front();
  this->_stack.pop_front();
  return ret;
}

void	Stack::add()
{
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*newVal;
  
  if (this->_stack.size() < 2)
    throw myException("Less than 2 operands in the stack");
  val1 = this->getTop();
  val2 = this->getTop();
  if (val1->getPrecision() > val2->getPrecision())
    newVal = this->createOperand(val1->getType(), val1->toString());
  else
    newVal = this->createOperand(val2->getType(), val1->toString());
  newVal = *newVal + *val2;
  this->_stack.push_front(newVal);
}

void	Stack::sub()
{
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*newVal;
  
  if (this->_stack.size() < 2)
    throw myException("Less than 2 operands in the stack");
  val1 = this->getTop();
  val2 = this->getTop();
  if (val1->getPrecision() > val2->getPrecision())
    newVal = this->createOperand(val1->getType(), val1->toString());
  else
    newVal = this->createOperand(val2->getType(), val1->toString());
  newVal = *newVal - *val2;
  this->_stack.push_front(newVal);
}

void	Stack::mul()
{
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*newVal;
  
  if (this->_stack.size() < 2)
    throw myException("Less than 2 operands in the stack");
  val1 = this->getTop();
  val2 = this->getTop();
  if (val1->getPrecision() > val2->getPrecision())
    newVal = this->createOperand(val1->getType(), val1->toString());
  else
    newVal = this->createOperand(val2->getType(), val1->toString());
  newVal = *newVal * *val2;
  this->_stack.push_front(newVal);
}

void	Stack::div()
{
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*newVal;
  
  if (this->_stack.size() < 2)
    throw myException("Less than 2 operands in the stack");
  val1 = this->getTop();
  val2 = this->getTop();
  if (val2->toString() == "0")
    throw myException("Division by 0");
  if (val1->getPrecision() > val2->getPrecision())
    newVal = this->createOperand(val1->getType(), val1->toString());
  else
    newVal = this->createOperand(val2->getType(), val1->toString());
  newVal = *newVal / *val2;
  this->_stack.push_front(newVal);
}

void	Stack::mod()
{
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*newVal;

  if (this->_stack.size() < 2)
    throw myException("Less than 2 operands in the stack");
  val1 = this->getTop();
  val2 = this->getTop();
  if (val2->toString() == "0")
    throw myException("Division by 0");
  if (val1->getPrecision() > val2->getPrecision())
    newVal = this->createOperand(val1->getType(), val1->toString());
  else
    newVal = this->createOperand(val2->getType(), val1->toString());
  newVal = *newVal % *val2;
  this->_stack.push_front(newVal);
}
