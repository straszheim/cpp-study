#include "study.hpp"
#include <numeric>

namespace N1 
{
  struct A 
  { 
    int j;
  };
  void f(A a) { SHOW(); } // what if this was added by author of A
}

void f(N1::A a) { SHOW(); }

int main(int, char**)
{
  N1::A a;

  f(a);
}
