#include "study.hpp"

struct S 
{
  void foo(float f) const { SHOW() << f << "\n"; }

  int x;
};



int main() {

  S* s = new S;
  S& s2 = *s;

  void (S::*fnptr)(float) const = &S::foo;
  
  (s->*fnptr)(3.14159);
  (s2.*fnptr)(3.14159);

  int S::*memptr = &S::x;

  s->x = 1313;

  std::cout << s->*memptr << "\n";
  std::cout << s2.*memptr << "\n";


  

}
