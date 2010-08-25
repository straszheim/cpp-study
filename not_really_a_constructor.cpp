#include "study.hpp"

struct Bar 
{ 
  void f() { SHOW(); }
  Bar g() { SHOW(); return Bar(); }
};
struct Foo { 
  Foo() { SHOW(); }
  Foo(const Bar&) { SHOW(); }
  void f() { SHOW(); }
};

Bar retbar() { SHOW(); return Bar(); }

// valid decls:

Foo x(Bar());
Foo x(Bar(*)());
Foo x(Bar(*fn)());

// valid defs:
Foo x(Bar(fn)()) {
  SHOW();
  fn();
  return Foo();
}

Foo y(Bar()) {
  SHOW();
  return Foo();
}


Foo z(Bar(Bar::*)()) {
  SHOW();
  return Foo();
}

int main() 
{
  // Bar b;
  Foo x(Bar(*sth)());
  //x.f();
  x(retbar);
  y(retbar);
  z(&Bar::g);
  return 0;
}
