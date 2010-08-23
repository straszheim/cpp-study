// 2 concepts:  qualified and dependent names

// std::cout   <- cout is qualified name
//
// template <class T> struct S { 
//    T::bang x;  <- bang is dependent
// };  
//

//
// "qualified dependent names should be parsed as non types even
// if it leads to a syntax error"
//

// you need it when your name is both dependent (on a template
// parameter)  and qualified (contains a scope operator)

#include "study.hpp"
#include <vector>
using std::vector;

template <class T>
struct again {
  typedef T type;
};

template <class T>
struct MyClass {

  // these are known at time of declaration
  int i;
  vector<int> vi;
  vector<int>::iterator vitr;
   
  // these are not known until instantiation, they are *dependent*
  T t;
  vector<T> vt;
  typename vector<T>::iterator viter; 

  typename again<typename again<typename again<T>::type>::type>::type donk;

};

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

  MyClass<int> mi;
  MyClass<float> mf;

}




