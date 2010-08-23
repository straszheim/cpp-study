#include "study.hpp"


template <unsigned I> 
struct factorial 
{
  const static unsigned value = I * factorial<I-1>::value;
};

template <>
struct factorial<1> 
{
  const static unsigned value = 1;
};

template <>
struct factorial<0> 
{
  const static unsigned value = 1;
};

int main() 
{
  std::cout << factorial<0>::value << " "
	    << factorial<1>::value << " "
	    << factorial<2>::value << " "
	    << factorial<3>::value << " "
	    << factorial<4>::value << " "
	    << factorial<5>::value << "\n";

}

