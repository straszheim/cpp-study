//
//  what does this program print
//
#include "study.hpp"
#include <iostream>
#include <complex>
using namespace std;

class Base {
public:
  virtual void f( int ) { SHOW(); }

  virtual void f( double ) { SHOW(); }

  virtual void g( int i = 10 ) { SHOW() << i << "\n";
  }
};

class Derived: public Base {
public:
  void f( complex<double> ) { SHOW(); }

  void g( int i = 20 ) { 
    SHOW() << i << "\n";
  }
};

int main() 
{
  Base    b;
  Derived d;
  Base*   pb = new Derived;

  b.f(1.0);
  d.f(1.0);
  pb->f(1.0);

  b.g();
  d.g();
  pb->g();

  delete pb;
  return 0;
}
