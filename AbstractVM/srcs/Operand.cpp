#include <limits>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "../headers/Exception.hh"
#include "../headers/Operand.hh"

template <typename T>
Operand<T>::Operand(const std::string &value, const eOperandType &type)
{
  std::stringstream	tmp;
  long double		cmpvalue;

  tmp << value;
  tmp >> cmpvalue;
  if (cmpvalue > std::numeric_limits<T>::max())
    throw myException("Type T overflow");
  else if (cmpvalue < std::numeric_limits<T>::min())
    throw myException("Type T underflow");
  this->_value = cmpvalue;
  this->_type = type;
}

template <typename T>
Operand<T>::~Operand()
{
}

template <>
std::string const	&Operand<char>::toString() const
{
  std::stringstream	tmp;
  std::string		*ret = new std::string;

  tmp << static_cast<int>(this->_value);
  *ret = tmp.str();
  return *ret;
}

template <typename T>
std::string const	&Operand<T>::toString() const
{
  std::stringstream	tmp;
  std::string		*ret = new std::string;

  tmp << this->_value;
  *ret = tmp.str();
  return *ret;
}

template <typename T>
int	Operand<T>::getPrecision() const
{
  return this->_type;
}

template <typename T>
eOperandType	Operand<T>::getType() const
{
  return this->_type;
}

template <typename T>
long double	Operand<T>::castCalc(const std::string &val1,
				     const std::string &val2, const char &ope) const
{
  std::stringstream	tmpVal1;
  std::stringstream	tmpVal2;
  long double		cVal1;
  long double		cVal2;

  tmpVal1 << val1;
  tmpVal2 << val2;
  tmpVal1 >> cVal1;
  tmpVal2 >> cVal2;
  switch (ope)
    {
    case '+':
      return (cVal1 + cVal2);
    case '-':
      return (cVal1 - cVal2);
    case '*':
      return (cVal1 * cVal2);
    default:
      return (cVal1 / cVal2);
    }
}

template <typename T>
IOperand	*Operand<T>::operator+(const IOperand &rhs) const
{
  IOperand		*ret;
  long double		result = this->castCalc(this->toString(),
						rhs.toString(), '+');
  std::stringstream	strRes;

  if (result < std::numeric_limits<T>::min())
    throw myException("Type underflow");
  else if (result > std::numeric_limits<T>::max())
    throw myException("Type overflow");
  strRes << result;
  ret = new Operand<T>(strRes.str(), this->getType());
  return ret;
}

template <typename T>
IOperand	*Operand<T>::operator-(const IOperand &rhs) const
{
  IOperand		*ret;
  long double		result = this->castCalc(this->toString(),
						rhs.toString(), '-');
  std::stringstream	strRes;

  if (result < std::numeric_limits<T>::min())
    throw myException("Type underflow");
  else if (result > std::numeric_limits<T>::max())
    throw myException("Type overflow");
  strRes << result;
  ret = new Operand<T>(strRes.str(), this->getType());
  return ret;
}

template <typename T>
IOperand	*Operand<T>::operator*(const IOperand &rhs) const
{
  IOperand		*ret;
  long double		result = this->castCalc(this->toString(),
						rhs.toString(), '*');
  std::stringstream	strRes;
  
  if (result < std::numeric_limits<T>::min())
    throw myException("Type underflow");
  else if (result > std::numeric_limits<T>::max())
    throw myException("Type overflow");
  strRes << result;
  ret = new Operand<T>(strRes.str(), this->getType());
  return ret;
}

template <typename T>
IOperand	*Operand<T>::operator/(const IOperand &rhs) const
{
  IOperand		*ret;
  long double		result = this->castCalc(this->toString(),
						rhs.toString(), '/');
  std::stringstream	strRes;

  if (result < std::numeric_limits<T>::min())
    throw myException("Type underflow");
  else if (result > std::numeric_limits<T>::max())
    throw myException("Type overflow");
  strRes << result;
  ret = new Operand<T>(strRes.str(), this->getType());
  return ret;
}

template <typename T>
IOperand	*Operand<T>::operator%(const IOperand &rhs) const
{
  IOperand		*ret;
  long int		result;
  std::stringstream	strRes;
  std::stringstream	strVal1;
  std::stringstream	strVal2;
  long int		val1;
  long int		val2;

  strVal1 << this->toString();
  strVal2 << rhs.toString();
  strVal1 >> val1;
  strVal2 >> val2;
  result = val1 % val2;
  strRes << result;
  ret = new Operand<T>(strRes.str(), this->getType());
  return ret;
}

template <>
IOperand	*Operand<float>::operator%(const IOperand &) const
{
  throw myException("Modulo with float");
  return NULL;
}

template <>
IOperand	*Operand<double>::operator%(const IOperand &) const
{
  throw myException("Modulo with float");
  return NULL;
}

template class Operand<char>;
template class Operand<short int>;
template class Operand<int>;
template class Operand<float>;
template class Operand<double>;
