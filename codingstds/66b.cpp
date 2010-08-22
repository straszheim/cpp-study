#include "study.hpp"
#include <algorithm>
#include <vector>

namespace std {

  template <typename T>
  inline void munge_impl(T& lhs, T& rhs)
  {
    SHOW();
  }

  template <typename T>
  inline void munge(T& lhs, T& rhs)
  {
    SHOW();
    munge_impl(lhs, rhs);
  }
  
}

namespace B {

  struct S { };

  void munge_impl(S& lhs, S& rhs)
  {
    SHOW() << "MYIMPL\n";
  }
    
  template <typename T>
  struct W 
  { };
}

namespace std {
  template <>
  void munge_impl(B::W<int>& lhs, B::W<int>& rhs)
  {
    SHOW() << "MYOTHERIMPL\n";
  }

}

int main()
{

  B::S s1, s2;
  B::W<int> w1, w2;

  std::munge(s1, s2);
  std::munge(w1, w2);

}
