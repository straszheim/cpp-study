#include "study.hpp"

// w/o the _ param you get a "explicit specialization in non-namespace
// scope"

struct Outer {

  struct specialized_t { };
  struct unspecialized_t { };

  template <typename T, typename _ = void>
  struct Inner {
    typedef T type;
  };

  template <typename _>
  struct Inner<bool, _> {
    typedef specialized_t type;
  };
};

int main()
{
  std::cout << "general:" << name_of<Outer::Inner<float>::type>() << "\n";
  std::cout << "special:" << name_of<Outer::Inner<bool>::type>() << "\n";
}
