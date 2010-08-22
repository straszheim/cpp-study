#include "study.hpp"
#include <algorithm>
#include <vector>

int value() {
  static int j = 0;
  j %= 5;
  return j++;
}

namespace N {

  template <typename T>
  struct W 
  { 
    int j;
    W() 
    { 
      j = value();
    }

    W(const W& rhs) 
    { 
      j = rhs.j;
    }
    W& operator=(const W& rhs)
    {
      j = rhs.j;
      return *this;
    }

    void swap(W& rhs) {
      SHOW() << "&&&&&&&&&&&&&&&&&&&&&&\n";
      int tmp = rhs.j;
      rhs.j = j;
      j = tmp;
    }
  };

  template <typename T>
  bool operator<(const W<T>& lhs, const W<T>& rhs)
  {
    return lhs.j < rhs.j;
  }
  
  // WORKS
  template <typename T>
  void swap(W<T>& lhs, W<T>& rhs)
  {
    SHOW() << "$$$$$$$$$$$$$$$$$$$$$$\n";
    lhs.swap(rhs);
  }
}

// ALSO WORKS
namespace std {

  // if you take out the overload in namespace N,
  // this will get called... but with both the overload
  // is preferred to the specialization
  template <>
  inline void swap(N::W<float>& lhs, N::W<float>& rhs)
  {
    SHOW() << "!!!!!!!!!!!!!!!!!!!!!!";
    N::W<float> tmp(lhs);
    rhs = lhs;
    lhs = tmp;
  }

  // NO WORK
  /*
  template <typename T>
  inline void swap(N::W<T>& lhs, N::W<T>& rhs)
  {
    SHOW();
    N::W<T> tmp(lhs);
    rhs = lhs;
    lhs = tmp;
  }
  */

  // NO WORK
  /* 
  inline void swap(N::W<float>& lhs, N::W<float>& rhs)
  {
    SHOW() << "*****************\n";
    N::W<float> tmp(lhs);
    rhs = lhs;
    lhs = tmp;
  }
  */
}


using std::swap;

int main()
{
  N::W<float> w1, w2;

  swap(w1, w2);

  std::cout << "SHOULD HAVE BEEN ONE JUST NOW\n";

  std::vector<N::W<bool> > vi;
  for (int i=0; i<25; i++)
    {
      N::W<bool> nw;
      vi.push_back(nw);
    }

  std::cout << "START SORT: SHOULD SEE MANY \n";

  std::sort(vi.begin(), vi.end());
}


// so.
// call std::swap and you get std::swap no matter what
// if std::swap is in the lookup either via using std::swap
// or using namespace std::swap, you get the right one.

// with those you need one of two things
// an overload in the namespace of the class
// or a specialization in namespace std; 
