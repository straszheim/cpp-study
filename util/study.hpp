#include "name_of.hpp"

#define stringizeimpl(X) #X
#define stringize(X) stringizeimpl(X)

#pragma GCC diagnostic ignored "-Wformat-security"
#include <iostream>
#define SHOW()  std::cout << __PRETTY_FUNCTION__ << "\n"

#define log(FMT, ...) log_impl(__FILE__, __LINE__, __PRETTY_FUNCTION__, FMT, ##__VA_ARGS__)

template <typename... Args>
void log_impl(const char* file, int line, const char* pf, const char* fmt, Args&... args)
{
  //  printf("%s:%d %s ", file, line, pf);
  printf("%s ", pf);
  printf(fmt, args...);
  printf("\n");
}

template <typename T>
struct verbose {

  const std::string name;
  verbose() : name(name_of<T>())
  {
    std::cout << this << " " << name << "::" << name << "()\n";
  }

  verbose(const verbose& rhs) : name(name_of<T>())
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
