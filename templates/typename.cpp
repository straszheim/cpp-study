#include "study.hpp"

template <typename T>
void foo()
{
  typename T::X x;
  x = 17;
}

template <typename T>
struct C
{
  typedef T X;
  typedef float Y;
  C::Y r;
};


int main()
{
  // here's the ambiguous bit:
  int (r); // this is a variable declaration
  r = 0;

  foo<C<int> >();


}




