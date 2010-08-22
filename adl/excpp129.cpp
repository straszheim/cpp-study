#include "study.hpp"

namespace N1 
{
  struct A 
  { 
    int j;
  };
  void f(A a) { SHOW(); }
}

struct B {

  void f(N1::A a) { SHOW(); }

  void g(N1::A arg) 
  {
    f(arg);
  }
};

void f(N1::A a) { SHOW(); }

int main(int, char**)
{
  N1::A a;
  B b;

  b.g(a);
}
