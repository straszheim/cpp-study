#include "util/study.hpp"

template <typename Fn, typename ...Args>
auto callfwd(Fn&& fn, Args&&... args) -> decltype(fn(args...))
{
  SHOW();
  return fn(std::forward<Args>(args)...);
}

int main(int, char**) {

  auto&& thingy = [](auto&& r, auto&& j, auto&& k) {
    SHOW();
    r = j * k;
    return "whee";
  };

  int four = 4;
  float two = 2.0;
  double five = 5.0;
  const volatile double& fiver = five;

  callfwd(thingy, two, four, fiver);
  assert(two == 20.0);
}
