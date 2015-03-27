#ifndef PARSER_HH_
# define PARSER_HH_

# include <string>
# include "IOperand.hh"

class	Parser
{
private:
  const std::string		epur_str(const std::string &_src);
  std::list<std::string>	tokenize_string(const std::string &_src);

  bool	correct_value(const std::string &_type, const std::string &_value);
  bool	correct_type(const std::string &_type);
  int	correct_inst(const std::string &_inst);

  bool	complex_inst_check(const std::string &_inst);
  bool	simple_inst_check(const std::string &_inst);

  bool	simple_inst(std::list<std::string> &_cmd);
  bool	complex_inst(std::list<std::string> &_cmd);
public:
  Parser();
  ~Parser();

  eOperandType			typeValue(const std::string &_type);
  
  const std::list<std::string>	avm_lexer(const std::string &_str);
  void				avm_parser(std::list<std::string> &_cmd);
};

#endif /* !PARSER_HH_ */
