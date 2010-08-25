#include "study.hpp"

template <typename T>
struct alloc 
{
  template <typename U>
  struct rebind 
  {
    typedef alloc<U> type;
  };
};

template <typename T, typename Alloc = alloc<T> >
struct container 
{
  typedef typename Alloc::template rebind<float>::type rebound_t;
};




int main()
{
  container<int> c;
}
