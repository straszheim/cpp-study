#include "study.hpp"
#include <string>

struct B
{
  void f(int) { SHOW(); }
  void f(double){ SHOW(); }

  void g(int){ SHOW(); }
};

struct D : B 
{
  using B::g;

private:

  void g(std::string, bool){ SHOW(); }
};

int main(int, char**)
{
  D d;
  int i = 0;
  d.f(i);
  d.B::g(i);
  
  d.g(i); // works thx to using
}

