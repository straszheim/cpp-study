
#include "study.hpp"

namespace N {

  class C {

    int j;

    friend std::ostream& operator<<(std::ostream& os, C& c)
    {
      return os << "[C with " << c.j << "]";
    }

  public:
    C(int j_) : j(j_) { }
  
  };
}

int main()
{
  N::C c(77), d(99);

  std::cout << c << "\n" << d << "\n";
}
  
