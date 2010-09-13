#include "study.hpp"

// no templates
// apparently no friend

template <typename T> struct templ { };

int main() {

  struct foo {
    foo() { SHOW(); }
    ~foo() { SHOW(); }
    //friend std::ostream& operator<<(std::ostream& os, const foo& f) {
    //      SHOW(); 
    //      return os; 
    //    }
  } somefoo;

  struct bar {
    struct baz {
      baz() { SHOW(); }
      ~baz() { SHOW(); }
    };
  };
  bar::baz mybaz;

}

