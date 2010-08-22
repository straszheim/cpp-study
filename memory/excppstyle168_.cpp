/* 
  which operator news are called for each function here
*/

#include "study.hpp"
#include <stdlib.h>


struct FastMemory { };


class B {
public:
  
  // this guy hides the globals.  
  static void* operator new(std::size_t s, const FastMemory& fm)
  {
    SHOW();
    return malloc(s);
  }


  //
  //  how about using ::operator new;  here?  works or not?
  //

  // you have to provide "plain" (no extra params) news as well
  static void* operator new(std::size_t s) throw (std::bad_alloc)
  {
    SHOW();
    return ::operator new(s);
  }

  static void* operator new(std::size_t s, const std::nothrow_t& nt) throw()
  {
    SHOW();
    return ::operator new(s, nt);
  }

  static void* operator new(std::size_t s, void* p) throw()
  {
    SHOW();
    return ::operator new(s, p);
  }

};

class D : public B 
{

};


int main() 
{
  D* p1 = new D; // no match

  D* p2 = new (std::nothrow) D; // no match

  void* p3 = malloc(sizeof(D)); // no match
  new (p3) D;

  D* p4 = new (FastMemory()) D; // Base::operator new
}


