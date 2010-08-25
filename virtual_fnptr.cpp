#include "study.hpp"

struct B 
{
  virtual void foo() { SHOW(); }
};

struct D : B {
  virtual void foo() { SHOW(); }
};  

int main() {

  B* b = new D;

  void (B::*b_foo)() = &B::foo;
  void (D::*d_foo)() = &D::foo;


  (b->*b_foo)();
  b = new B;
  (b->*b_foo)();

  // call derived fn via derived* memfn and  ptr-to-base: error
  // (b->*d_foo)();
}

// there is no difference...  virtual functions are dispatched
// depending on RT type of object

