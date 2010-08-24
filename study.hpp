#include "name_of.hpp"


#include <iostream>
#define SHOW()  std::cout << __PRETTY_FUNCTION__ << "\n"



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
