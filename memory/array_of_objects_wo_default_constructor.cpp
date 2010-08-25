#include "study.hpp"

struct C { int x;
  C(int x_) : x(x_) { SHOW() << x << "\n";; }
  ~C() { SHOW() << x << "\n"; }
};

int main() {

  void* raw = operator new(3 * sizeof(C));
  C* cp = static_cast<C*>(raw);
  for (unsigned i=0; i<3; ++i)
    new (cp+i) C(i);

  for (unsigned i=0; i<3; ++i)
    cp[i].~C();

  // NOOOO, nasal demons
  // operator delete[](cp)

  operator delete[](raw);
  
}
