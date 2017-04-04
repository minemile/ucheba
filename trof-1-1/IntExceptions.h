#ifndef INTEXCEPT_H
#define INTEXCEPT_H

#include <stdexcept>
#include <string>

class MyException: public std::runtime_error
{
public:
  MyException(const std::string &s):
                     std::runtime_error(s) { }
};

class EOverflow: public MyException
{
public:
  EOverflow(const std::string &s): MyException(s) { }
  EOverflow(const std::string &s,
      const std::string &lhs, const std::string &rhs):
      MyException(s), left(lhs), right(rhs) { }
  const std::string left, right;
};

class EDivideByZero: public MyException
{
public:
  EDivideByZero(const std::string &s): MyException(s) { }
  EDivideByZero(const std::string &s, const std::string &lhs): MyException(s), left(lhs) { }
  const std::string left;
};

#endif
