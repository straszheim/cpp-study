/*

  unqualified names in a template (like the error in_base) are
  generally non-dependent and must be looked up when the template is
  defined.  But we don't know the definition of the base class yet
  (maybe there is a specialization coming up that we havent seen yet)
  so unqualified names are never resolved to the members of the
  base class.
 */

#include <iostream>
 
template <typename T>
struct base {
  T in_base;
};

template <typename T>
struct derived : base<T>
{
  void foo() {
    // in_base = 9; // error!  
    this->in_base = 7;
    base<T>::in_base = 8;

    // also you can do using base<T>::in_base;

  }
};

 
int main()
{
  derived<int> di;
}
