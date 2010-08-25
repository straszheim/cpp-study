#include "study.hpp"

//
//  apparently typename is used when name is both dependent
//  and "qualified" or -> or .
//

template <typename T, typename U>
void foo(T t, U u)
{
  t.bing(u); // sit one... after dot
  t.template noargs<U>();
  t.template onearg<U>(t);
}

template <typename T, typename U>
void foo(T* t, U u)
{
  t->bing(u); // sit two... after arrow
  t->template noargs<U>();
  t->template onearg<U>(t);
}

template <typename T>
void foo() // sit three... after scope operator
{
  T::template D<bool>::foo();
}

struct C
{
  template <typename T>
  void bing(T t) {
    SHOW();
  }

  template <typename T>
  void noargs() {
    SHOW();
  }

  template <typename T, typename U>
  void onearg(U u) {
    SHOW();
  }

  template <typename T>
  struct D
  {
    static void foo() { SHOW(); }
  };

};
 
namespace n {
  template <typename T>
  static void fn() 
  { 
    SHOW();
  }
}
    
template <typename T>
struct nprime {
  template <typename U>
  struct inner {
    template <typename V>
    static void fn() 
    { 
      SHOW();
    }
  };
};

int main()
{
  C c;
  int r = 0;

  foo(c, r);
  foo(&c, r);

  foo<C>();

  n::fn<void>();                         // not dependent
  nprime<void>::inner<void>::fn<void>(); // not dependent
}
