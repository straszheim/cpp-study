// implement pre/post increment for a UDT.
// why is preincrement faster
// when can compilers optimize the postincrement

// postincrement is the one that takes an int postinc should return a
// const T so that t++++ doesn't work (it increments a temporary the
// second time)
//
#include "study.hpp"

struct T {
  int j;

  T() : j(0) { };

  T& operator++() {
    SHOW();
    j += 1;
    return *this;
  }

  const T operator++(int) {
    SHOW();
    T tmp = *this;
    j += 1;
    return tmp;
  }
};

std::ostream& operator<<(std::ostream& os, const T& t)
{
  return os << "[T " << t.j << "]";
}


int main()
{
  {
    T t;
    std::cout << "postinc\n" << t << "\n";
    std::cout << t++ << "\n";
    std::cout << t++ << "\n";
    // std::cout << t++++ << "\n"; this shouldn't compile
  }
  {
    T t;
    std::cout << "preinc\n" << t << "\n";
    std::cout << ++t << "\n";
    std::cout << ++t << "\n";
    std::cout << ++++t << "\n"; // this is okay
  }
}
