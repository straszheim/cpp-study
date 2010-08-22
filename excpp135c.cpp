#include "study.hpp"
#include <string>

namespace B
{
  void f(int) { SHOW(); }
  void f(double){ SHOW(); }

  void g(int){ SHOW(); }
};

namespace D
{
  using B::g;

  void g(std::string, bool){ SHOW(); }
};

int main(int, char**)
{
  using namespace D;
  int i = 0;

  g(i);
}

