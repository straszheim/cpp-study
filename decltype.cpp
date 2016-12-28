#include "util/study.hpp"

template <typename ArgType>
void foo(ArgType&& param)
{
  std::cout << "ArgType: " << type_id_with_cvr<ArgType>().pretty_name() << "\n";
  std::cout << "param type: " << type_id_runtime(param).pretty_name() << "\n";
  PN(param);
}

int main(int, char**) {

  foo(13);
  volatile int k = 13;

  const volatile int& j = k;
  foo(j);

  auto makestring = [](const char* what) {
    return std::string(what);
  };

  foo(makestring("what"));

  std::string s;
  foo(std::move(s));

  static_assert(std::is_rvalue_reference<int&&>(), "needs to be rval ref");

  auto likes_rvals = [](auto&& rv) {
    std::cout << "rv is " << type_id_with_cvr<decltype(rv)>().pretty_name() << "\n";
    assert(std::is_rvalue_reference<decltype(rv)>());
  };

  likes_rvals(makestring("huh"));
  likes_rvals(std::move(s));
  likes_rvals(s);

  

}
