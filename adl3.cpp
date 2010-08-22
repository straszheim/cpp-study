#include "study.hpp"
#include <algorithm>

namespace N1 
{
  struct A 
  { 
    int j;
  };

}

N1::A operator+(const N1::A& lhs, const N1::A& rhs)
{
  SHOW();
  N1::A tmp;
  tmp.j = lhs.j + rhs.j;
  return tmp;
}

int main(int, char**)
{
  N1::A a, b, c;
  c = a + b;
}
