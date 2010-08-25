#include <stdlib.h>
#include "study.hpp"
#include <memory>

void* operator new(std::size_t s) throw(std::bad_alloc)
{
  void* buf = malloc(s);
  if (s == 0) throw std::bad_alloc();
  SHOW() << "buf=" << buf << "\n";
  return buf;
}

void operator delete(void* buf) {
  SHOW() << "buf=" << buf << "\n";
  free(buf);
}

struct C { float x, y, z; };

int main() {
  
  const std::auto_ptr<C> cp(new C);
}
