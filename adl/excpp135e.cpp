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
  using namespace B;

  void g(std::string, bool){ SHOW(); }
};

int main(int, char**)
{
  int i = 0;

  D::f(i);
  D::g(i);
}

