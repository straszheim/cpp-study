#include "study.hpp"

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
using namespace boost;

template <typename T>
void bing(T t, typename enable_if<is_arithmetic<T> >::type* ptr = 0)
{
  SHOW();
}

struct C { };


template <typename T>
typename enable_if<is_arithmetic<T>, void>::type
bong(T t)
{
  SHOW();
}

template <typename T, typename _ = typename enable_if<is_arithmetic<T> >::type>
struct boom
{
  boom() { SHOW(); }
};


template <typename T, typename _ = void>
struct blam 
{ 
  blam() { SHOW() << "NADA\n"; }
};

template <typename T>
struct blam<T, typename enable_if<is_integral<T> >::type>
{
  blam() { SHOW() << "INTEGRAL\n"; }
};

template <typename T>
struct blam<T, typename enable_if<is_float<T> >::type>
{
  blam() { SHOW() << "FLOAT\n"; }
};


int main() 
{
  
  bing(13);
  // this shouldn't compile
  //bing("donk donk");

  bong(13);
  // this shouldn't compile
  // bong("donk donk");

  boom<int> b;
  //  boom<std::string> b;

  blam<int> bi;
  blam<float> bf;
  blam<C> bc;

}
