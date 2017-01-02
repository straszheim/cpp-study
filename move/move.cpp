#include "util/study.hpp"
#include "util/c.hpp"

int main(int, char**)
{
  assert(C::population == 0);
  C c("one");
  REPORT(c);
  assert(C::population == 1);
  auto make_c = [](const char* n) { return C(n); };
  // copy elision occurs
  C c2 = make_c("two");
  assert(C::population == 2);

  REPORT(c2);

#pragma GCC diagnostic ignored "-Wpessimizing-move"
  // this one involves a move
  auto make_c2 = [](const char* n) { C c(n); REPORT(c); return std::move(c); };
  C c3 = make_c2("three");
  
  REPORT(c3);
  assert(C::population == 3);

  // no move here
  auto make_nomove = [](const char* n) { C c(n); REPORT(c); return c; };
  C c4 = make_nomove("four");
  REPORT(c4);

  assert(C::population == 4);

  c4 = make_nomove("five");
  REPORT(c4);

  assert(C::population == 4);

#pragma GCC diagnostic ignored "-Wtautological-pointer-compare"

  assert(&c != nullptr);


  std::swap(c3, c4);
  assert(C::population == 4);
  REPORT(c3);
}
