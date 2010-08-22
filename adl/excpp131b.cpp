
#include <iostream>

class X { };

std::ostream& operator<<(std::ostream& os, const X& x)
{
  os << "[X at " << &x << "]";
  return os;
}


struct Y 
{ 
  virtual std::ostream& print(std::ostream& os) const
  {
    os << "[Y at " << this <<"]";
    return os;
  }
};

std::ostream& operator<<(std::ostream& os, const Y& y) 
{
  return y.print(os);
}




int main(int, char**)
{
  X x;
  std::cout << x << "\n";

  Y y;
  std::cout << y << "\n";
}


















/*
  X version has same dependencies as Y's:  both actually depend on
  ostream because operator<< is part of the interface.

  Y's version will print correctly for a class DerivedFromY
 */
