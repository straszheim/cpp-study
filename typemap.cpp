#include <typeinfo>
#include <iostream>
#include <vector>

template <typename T>
struct my_container
{
  template <typename U, typename _ = void>
  struct typemap {
    typedef U type;
  };

  template <typename _>
  struct typemap<bool, _> 
  {
    typedef char type;
  };

  template <typename U>
  struct again
  {
    typedef U type;
  };

  typedef typename again<typename typemap<T>::type>::type element_type;
  std::vector<element_type> storage_;
  typedef std::vector<T> vectorthing;

  my_container() {
    std::cout << "element_type == " << typeid(element_type).name() << "\n";
  }

};


int main() 
{
  my_container<bool> b;
  my_container<char> c;
  my_container<float> f;
}
