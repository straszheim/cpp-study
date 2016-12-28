#include "name_of.hpp"
#include <type_traits>
#include <cassert>
#include <vector>

#define stringizeimpl(X) #X
#define stringize(X) stringizeimpl(X)

#pragma GCC diagnostic ignored "-Wformat-security"
#include <iostream>
#define SHOW()  std::cout << __PRETTY_FUNCTION__ << "\n"

#define log(FMT, ...) log_impl(__FILE__, __LINE__, __PRETTY_FUNCTION__, FMT, ##__VA_ARGS__)

using std::is_rvalue_reference;

template <typename Arg>
void pn(Arg&&, const char* n = "")
{
  std::cout << n << " = " << boost::typeindex::type_id_with_cvr<Arg>().pretty_name() << "\n";
}

#define PN(X) pn(X, BOOST_PP_STRINGIZE(X))

template <typename... Args>
void log_impl(const char* file, int line, const char* pf, const char* fmt, Args&&... args)
{
  //  printf("%s:%d %s ", file, line, pf);
  printf("%s ", pf);
  printf(fmt, args...);
  printf("\n");
}

template <typename T>
struct verbose {

  const std::string name;
  verbose() : name(type_id<T>().pretty_name())
  {
    std::cout << this << " " << name << "::" << name << "()\n";
  }

  verbose(const verbose& rhs) : name(type_id<T>().pretty_name())
  {
    std::cout << this << " " << name << "::" << name << "(const " << name << "&)\n";
  }
  verbose& operator=(const verbose& rhs)
  {
    std::cout << this << " " << name << "::operator=(const " << name << "&)\n";
    return *this;
  }

  ~verbose() {
    std::cout << this << " " << name << "::~" << name << "()\n";
  }
};
