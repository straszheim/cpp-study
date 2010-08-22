#include "study.hpp"
#include <numeric>

namespace N1 
{
  struct A 
  { 
    int j;
  };
  void f(A a) { SHOW(); } 
}

void f(N1::A a) { SHOW(); }

int main(int, char**)
{
  N1::A a;

  f(a);
}
