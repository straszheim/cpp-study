#include "study.hpp"

namespace N1 
{
  struct A { };
  void f(N1::A& a) { SHOW(); }
}

void f(int i) { SHOW(); }

int main(int, char**)
{
  N1::A a;
  f(a);
}
