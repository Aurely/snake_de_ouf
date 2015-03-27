#include <list>
#include <iostream>
#include "../headers/Exception.hh"
#include "../headers/Parser.hh"

Parser::Parser() {}

Parser::~Parser() {}

// LEXING FNCTS

const std::string	Parser::epur_str(const std::string &_src)
{
  int		srcPos = 0;
  std::string	ret;

  while (_src[srcPos])
    {
      if (_src[srcPos] == ' ' && _src[srcPos + 1] == ' ')
	++srcPos;
      else
	{
	  ret.push_back(_src[srcPos]);
	  ++srcPos;
	}
    }
  if (ret[0] == ' ')
    ret.erase(ret.begin());
  return ret;
}

std::list<std::string>	Parser::tokenize_string(const std::string &_src)
{
  std::list<std::string>	ret;
  std::string			tmp;
  std::size_t			pos = _src.find(" ");
  std::size_t			pos2;

  if (pos != std::string::npos && pos != 0)
    {
      tmp = _src.substr(0, pos);
      ret.push_back(tmp); // INST
      pos2 = _src.find("(", pos);
      if (pos2 != std::string::npos)
	{
	  tmp = _src.substr(pos + 1, pos2 - (pos + 1));
	  if (tmp != "")
	    ret.push_back(tmp); // TYPE
	  else
	    throw myException("Missing Type");
	  pos = _src.find(")", pos2);
	  if (pos != std::string::npos)
	    {
	      tmp = _src.substr(pos2 + 1, pos - (pos2 + 1));
	      if (tmp != "")
		ret.push_back(tmp); // VALUE
	      else
		throw myException("Missing Value");
	      if (_src[pos + 1])
		throw myException("Syntax Error");
	    }
	}
    }
  else
    ret.push_back(_src);
  return ret;
}

// LEXING EXEC

const std::list<std::string>	Parser::avm_lexer(const std::string &_str)
{
  std::list<std::string>	ret;
  std::string			tmp = _str;
  std::size_t			pos = _str.find(";");

  if (pos != std::string::npos && pos != 0)
    tmp = _str.substr(0, pos);
  tmp = epur_str(tmp);
  ret = tokenize_string(tmp);
  return ret;
}

// CORRECT CMD

eOperandType	Parser::typeValue(const std::string &_type)
{
  eOperandType	typeVal[5] = {Int8, Int16, Int32, Float, Double};
  std::string	typeCheck[5] = {"int8", "int16", "int32", "float", "double"};
  int		count = 0;
  
  while (count < 5)
    {
      if (typeCheck[count] == _type)
	return typeVal[count];
      ++count;
    }
  return Unknown;
}

bool	Parser::correct_value(const std::string &_type, const std::string &_value)
{
  eOperandType	typeVal = this->typeValue(_type);
  int		count = 0;
  int		flt = 0;

  while (_value[count])
    {
      if (_value[count] == '.')
	++flt;
      else if (_value[count] < '0' || _value[count] > '9')
	return 0;
      ++count;
    }
  if (flt == 0)
    return 1;
  else if ((typeVal == 3 || typeVal == 4) && flt == 1)
    return 1;
  else
    return 0;
}

bool	Parser::correct_type(const std::string &_type)
{
  if (this->typeValue(_type) != Unknown)
    return 1;
  return 0;
}

bool	Parser::complex_inst_check(const std::string &_inst)
{
  std::string	instTab[2] = {"push", "assert"};
  int		count = 0;

  while (count < 2)
    {
      if (instTab[count] == _inst)
	return 1;
      ++count;
    }
  return 0;
}

bool	Parser::simple_inst_check(const std::string &_inst)
{
  std::string	instTab[9] = {"pop", "add", "sub", "mul", "div",
			      "mod", "dump", "print", "exit"};
  int		count = 0;

  while (count < 9)
    {
      if (instTab[count] == _inst)
	return 1;
      ++count;
    }
  return 0;
}

int	Parser::correct_inst(const std::string &_inst)
{
  if (this->simple_inst_check(_inst) == 1)
    return 1;
  else if (this->complex_inst_check(_inst) == 1)
    return 2;
  else
    return 0;
}

// PARSER EXEC

bool	Parser::simple_inst(std::list<std::string> &_cmd)
{
  //  std::cout << "[" << _cmd.front() << "] < Instruction" << std::endl;
  if (this->correct_inst(_cmd.front()) == 1)
      return 1;
  else
      return 0;
}

bool	Parser::complex_inst(std::list<std::string> &_cmd)
{
  std::list<std::string>::iterator	it = _cmd.begin();
  std::string				cmdInst = *it;
  std::string				cmdType = *(++it);
  std::string				cmdValue = *(++it);

  //  std::cout << "[" << cmdInst << "] < Instruction [" << cmdType << "] < Type [" << cmdValue << "] < Value" << std::endl;
  if (this->correct_inst(cmdInst) == 2)
    {
      if (this->correct_type(cmdType) == 1)
	{
	  if (this->correct_value(cmdType, cmdValue) == 1)
	    return 1;
	  else
	    throw myException("Bad value");
	}
      else
	throw myException("Bad type");
    }
  else
    throw myException("Unknow instruction");
  return 0;
}

void	Parser::avm_parser(std::list<std::string> &_cmd)
{
  if (_cmd.size() == 1)
    {
      if (this->simple_inst(_cmd) == 1)
	return;
      else
	throw myException("Simple instruction failed");
    }
  else if (_cmd.size() == 3)
    {
      if (this->complex_inst(_cmd) == 1)
	return;
      else
	throw myException("Complex instruction failed");
    }
  else
    throw myException("Failed");
  //      std::cout << "Basic ERROR" << std::endl;
}
