#include "study.hpp"
#include <boost/mpl/bool.hpp>

namespace mpl = boost::mpl;

struct Clonable {
  void clone() { SHOW(); }
  typedef mpl::true_ clonable;
};

struct Copyable {
  void copy()  { SHOW(); }
  typedef mpl::false_ clonable;
};



template <typename T>
struct Classuser 
{
  T t;

  void doit() {
    impl(t, typename T::clonable());
  }
  
  void impl(T& t, mpl::true_)
  {
    t.clone();
  }

  void impl(T& t, mpl::false_)
  {
    t.copy();
  }
};


int main()
{
  Classuser<Clonable> clonable;
  clonable.doit();

  Classuser<Copyable> copyable;
  copyable.doit();
}

