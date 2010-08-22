//
// write a fast pimpl 
// 

#include "study.hpp"
#include <memory>


// x.hpp

class X {
  
  struct impl;
  const std::auto_ptr<impl> impl_;

public:

  X();
  int foo();

};


// fastalloc.hpp

class fastalloc {

  fastalloc();
  fastalloc(const fastalloc&);

public:
  
  static fastalloc& inst();

  void* alloc(std::size_t s)
  {
    SHOW();
    return ::operator new(s);
  }

  void dealloc(void* p) 
  {
    SHOW();
    ::operator delete(p);
  }

};

// fastalloc.cpp


fastalloc::fastalloc() { }

fastalloc& fastalloc::inst() 
{
  static fastalloc the_instance;
  return the_instance;
}
  
//
// fastpimpl
//
struct fastpimpl 
{
  void* operator new(std::size_t s) throw (std::bad_alloc)
  {
    return fastalloc::inst().alloc(s);
  }
  
  void operator delete(void* p) throw()
  {
    fastalloc::inst().dealloc(p);
  }
};

//
// x.cpp
//
struct X::impl : fastpimpl
{ 
  int foo() 
  { 
    return 7; 
  }
};
  
int X::foo() 
{
  SHOW();
  return impl_->foo();
}

X::X() 
  : impl_(new impl) 
{ }

//
// main
//
int main() 
{
  X x1, x2, x3;
  x1.foo();
  x2.foo();
  x3.foo();
}


//
//  probably there are free space penalties as it will be fragmented across
//  multiple lists
//

