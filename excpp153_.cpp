#include "study.hpp"
#include <memory>
// --- C.hpp --- 

class C {

  struct impl;
  const std::auto_ptr<impl> impl_; // auto_ptr is const

public:

  void foo();
  C();

};



// --- C.cpp ---

struct C::impl {  // out-of-line definition of nested class
  void foo() { 
    SHOW();
  }
};


C::C() 
  : impl_(new impl) 
{ }

void C::foo() {
  impl_->foo();
}


// --- main.cpp --- 

int main() {

  C c;
  c.foo();

}


// what is funny:  it takes nonconst reference
