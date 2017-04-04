#include <iostream>
#include <climits>
#include "MyInt.h"
#include "IntExceptions.h"

using std::cout;
using std::endl;

void print_error(const std::string s)
{
  cout << "Error: " + s << endl;
}
void test_init(void)
{
  int i = 1;
  MyInt a(2), b = (MyInt)i;
  if (a.get_int() != 2) print_error("a != 2");
  if (b.get_int() != 1) print_error("b != 1");
}

void test_comparison(void)
{
  MyInt a(2), b(1);
  if (a < b) print_error("a > b");
  if (!(a > b)) print_error("a < b");
  if (a == b) print_error("a == b");
  if (!(a!=b)) print_error("a != b");
}

void test_operations(void)
{
  MyInt a(4), b(2);
  if ((a + b) != 6) print_error("a+b!=6");
  if ((a - b) != 2) print_error("a-b!=2");
  if ((a * b) != 8) print_error("a*b!=8");
  if ((a / b) != 2) print_error("a/b!=2");
}

void test_exceptions(void)
{
  MyInt a(4), b(0), c(INT_MAX - 1), buf;
  try
  {
    buf = a / b;
  }
  catch (const EDivideByZero &e)
  {
    cout << "Got '" << e.what() << "' exception left operator = " << e.left << endl;
  }

  try
  {
    buf = a * c;
  }
  catch (const EOverflow &e)
  {
    cout << "Got '" << e.what() << "' exception left operator = " << e.left
    << ", right operator = " << e.right << endl;
  }
}

int main()
{
  test_init();
  test_comparison();
  test_operations();
  test_exceptions();
}
