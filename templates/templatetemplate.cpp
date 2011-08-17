
#include "study.hpp"
#include <vector>

struct X { };

template <template <class = X, class = X> class F,
          typename T1, typename T2>
struct invoke
{

  typedef F<T1, T2> type;
};

template <typename T = bool, typename U = float> struct invoked 
{ 
  invoked() { SHOW(); }
};


int main()
{
  invoke<invoked, int, bool>::type i1;

  invoke<invoked, X, double>::type i2;


}




