#include "study.hpp"
#include <stddef.h>

struct C {
  int one;
  float two;
  std::string three;
  int four;
};

int main() {
  C c;
  c.one = 1;
  c.two = 2.0;
  c.three = "three";
  c.four = 4;

  std::cout << "offset of two: " << offsetof(struct C,two);


}
