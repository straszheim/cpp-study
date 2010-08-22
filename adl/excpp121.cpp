#include "study.hpp"

namespace N1 
{
  struct A { };
}

void f(N1::A a) { SHOW(); };

int main(int, char**)
{
  N1::A a;
  f(a);
}
