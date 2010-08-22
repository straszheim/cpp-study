// implement nofail swap for

#include "study.hpp"

#include <vector>

class C {

  std::vector<float> v;
  int i;
  
public:

  C() { };

  C(const C& rhs) 
    : v(rhs.v),
      i(rhs.i)
  { 
    SHOW(); 
  }

  // variation 1
  C& operator=(const C& rhs)
  {
    SHOW();
    C tmp(rhs);
    swap(tmp);
    return *this;
  }

  /* variation 2
  C& operator=(C rhs)
  {
    SHOW();
    swap(rhs);
    return *this;
  }
  */

  void swap(C& rhs)
  {
    SHOW();
    v = rhs.v;
    std::swap(v, rhs.v);
    std::swap(i, rhs.i);
  }

};


int main() 
{
  C c1, c2;

  c1 = c2;
  std::swap(c1, c2);

}


// 1. you can use std::swap
// 2. hold by (shared) pointer
