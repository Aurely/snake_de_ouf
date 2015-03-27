#ifndef OPERAND_HH_
# define OPERAND_HH_

# include "IOperand.hh"

template<typename T>
class Operand : public IOperand
{
private:
  T		_value;
  eOperandType	_type;

  long double castCalc(const std::string &val1, const std::string &val2,
		       const char &ope) const;
public:
  Operand(const std::string &value, const eOperandType &type);

  virtual std::string const & toString() const;
  virtual int getPrecision() const;
  virtual eOperandType getType() const;

  virtual IOperand * operator+(const IOperand &rhs) const;
  virtual IOperand * operator-(const IOperand &rhs) const;
  virtual IOperand * operator*(const IOperand &rhs) const;
  virtual IOperand * operator/(const IOperand &rhs) const;
  virtual IOperand * operator%(const IOperand &rhs) const;

  virtual ~Operand();
};

#endif /* !OPERAND_HH_ */
