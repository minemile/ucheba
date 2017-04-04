#ifndef MYINT_H
#define MYINT_H

#include <iostream>
#include <string>
#include <climits>
#include "IntExceptions.h"

class MyInt {
public:
  MyInt(): n(0) {}; //Конструктор по умолчанию
  MyInt(const MyInt& other): n(other.n) {}; //Явное задание конструктора копий
  MyInt& operator=(const MyInt& other) { n = other.n; return *this; }; //Оператор присваивания копии
  MyInt(int number): n(number) {}; //Конструктор инициализации
  void operator<<(std::ostream& os) { os << n; }
  friend bool operator==(const MyInt&, const MyInt&);
  friend bool operator<(const MyInt&, const MyInt&);
  friend MyInt operator+(const MyInt&, const MyInt&);
  friend MyInt operator*(const MyInt&, const MyInt&);
  friend MyInt operator/(const MyInt&, const MyInt&);
  friend MyInt operator-(const MyInt&, const MyInt&);
  explicit operator int() const { return n; } //Явное преобразование типа

  int get_int() { return n; }
  ~MyInt(){}; //Деструктор

private:
  int n;
};

//Перегруженные операции сравнения
bool operator ==(const MyInt &a, const MyInt &b) { return a.n == b.n; }
bool operator !=(const MyInt &a, const MyInt &b) { return !(a == b); }
bool operator <(const MyInt &a, const MyInt &b) { return a.n < b.n; }
bool operator >(const MyInt &a, const MyInt &b) { return !(a < b); }
bool operator <=(const MyInt &a, const MyInt &b) { return a < b || a == b; }
bool operator >=(const MyInt &a, const MyInt &b) { return !(a <= b); }

//Перегруженные арифметические операции
MyInt operator+(const MyInt &a, const MyInt &b)
{
  long long temp = (long long)a.n + b.n;
  if (temp < INT_MIN || temp > INT_MAX){
    throw EOverflow("plus overflow", std::to_string(a.n), std::to_string(b.n));
  }
  return MyInt(a.n + b.n);
}

MyInt operator*(const MyInt &a, const MyInt &b)
{
  long long temp = (long long)a.n * b.n;
  if (temp < INT_MIN || temp > INT_MAX){
    throw EOverflow("mult overflow", std::to_string(a.n), std::to_string(b.n));
  }
  return MyInt(a.n * b.n);
}

MyInt operator-(const MyInt &a, const MyInt &b)
{
  long long temp = a.n - b.n;
  if (temp < INT_MIN || temp > INT_MAX){
    throw EOverflow("minus overflow", std::to_string(a.n), std::to_string(b.n));
  }
  return MyInt(a.n - b.n);
}

MyInt operator/(const MyInt &a, const MyInt &b)
{
  if (b.n == 0){
    throw EDivideByZero("Diveded by zero", std::to_string(a.n));
  }
  long long temp = a.n / b.n;
  if (temp < INT_MIN || temp > INT_MAX){
    throw EOverflow("division overflow", std::to_string(a.n), std::to_string(b.n));
  }
  return MyInt(a.n / b.n);
}

#endif
