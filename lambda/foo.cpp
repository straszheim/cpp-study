#include "util/study.hpp"

#define show(X) log("%s =%d (%p)", stringize(X), X, &X)

int main(int, char**) {

  int j = 3;

  auto fn = []() {
    int k = 71;
    auto fn2 = [k = k](int& i) {
      log("subwoot: %d %d", i, k);
    };

    log("woot");
    fn2(k);
  };

  int i = 1;
  auto makelam = [&]() {
    show(i);
    return [&]() {
      log("i=%d", i);
    };
  };

  log("i=%d", i);
  auto ll = makelam();
  i++;
  log("i=%d", i);
  ll();
  auto ll2 = makelam();
  i++;
  log("i=%d", i);
  ll();
  ll2();

}
