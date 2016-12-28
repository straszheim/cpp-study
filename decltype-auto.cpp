#include "util/study.hpp"

// '14 return type deduction
template <typename Container, typename Index>
decltype(auto) // if only auto, won't compile
getit(Container&& c, Index i)
{
  return std::forward<Container>(c)[i];
}

std::vector<int> gvi = {1,2,3,4,5};

std::vector<int>& make_vector() {
  return gvi;
}

int main(int, char**) {

  auto make_int = []() { return 3 * 4; };
  //  auto make_container = []() { return std::vector<int>{0,1,2,3,4}; };
  
  std::vector<int> vi = {1,2,3,4,5};
  assert(vi[2] == 3);
  getit(vi, 2) = make_int();
  assert(vi[2] == 12);

  assert(gvi[1] == 2);
  getit(make_vector(), 1) = make_int();
  assert(gvi[1] == 12);

  //  PN((decltype(getit(make_container(),2))));
  
}
