#include "study.hpp"

template <typename T>
struct injector 
{
  friend std::ostream& operator<<(std::ostream& os, const T& t)
  {
    return t.print(os);
  }
};

struct printy_base : injector<printy_base>
{
  virtual std::ostream& print(std::ostream&) const = 0;
};

struct X : printy_base
{
  std::ostream& print(std::ostream& os) const
  {
    return os << "[X]";
  }
};

struct Y : printy_base
{
  std::ostream& print(std::ostream& os) const
  {
    return os << "[Y]";
  }
};


int main() 
{
  X x;
  Y y;

  std::cout << x << y << "\n";

  printy_base &pb1(x), &pb2(y);
  
  std::cout << pb1 << pb2 << "\n";

}
