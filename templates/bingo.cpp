

#include "study.hpp"
#include <vector>

template <typename T,
	  typename U = std::vector<T>,
	  typename V = const T,
	  typename W = const T&>
struct gah
{ 
  typedef W plusconstref;
};


template <typename T>
void showit()
{
  typedef gah<T> gah_t;
  std::cout << name_of<gah<T> >() << "\n"
	    << name_of<typename gah<T>::plusconstref>() << "\n";
}


int main()
{

  showit<float>();
  showit<const float&>();



}
