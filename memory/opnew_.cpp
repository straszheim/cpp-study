/*

  write a class that prints it's op new/deletes.

 */	
#include <stdlib.h>
#include "study.hpp"

struct A 
{ 
  A() { SHOW(); }
  ~A() { SHOW(); }
};


void* operator new(std::size_t s) throw(std::bad_alloc)
{
  void *mem = malloc(s);
  if (mem == 0)
    throw std::bad_alloc();
  SHOW() << mem <<"\n";
  return mem;
}

void operator delete(void* p) throw()
{
  SHOW() << p << "\n";
  free(p);
}


int main()
{
  A* a = new A;
  delete a;
}
