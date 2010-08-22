#include "study.hpp"
#include <numeric>

namespace N1 
{
  struct A 
  { 
    int j;
  };

  A operator+(const A& lhs, const A& rhs)
  {
    SHOW();
    A tmp;
    tmp.j = lhs.j + rhs.j;
    return tmp;
  }
}

int main(int, char**)
{
  N1::A as[10], start;

  std::accumulate(as, as+10, start);
}
