/* 
  which operator news are called for each function here.

  what is the guidlines about providing class-specific new.
*/

#include "study.hpp"
#include <stdlib.h>


struct FastMemory { };


class B {
public:
  static void* operator new(std::size_t s, const FastMemory& fm)
  {
    return malloc(s);
  }
};

class D : public B {

};


int main() 
{
  D* p1 = new D;

  D* p2 = new (std::nothrow) D;

  void* p3 = malloc(sizeof(D));
  new (p3) D;

  D* p4 = new (FastMemory()) D;
}


