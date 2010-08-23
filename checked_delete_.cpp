#include "study.hpp"


struct T;


template <typename T>
void 
checked_delete(T* t)
{
  typedef char type_must_be_complete[sizeof(T) ? 0 : -1];
  (void) sizeof(type_must_be_complete);

  delete t;
};


int main() {
  
  // this is okay
  int* i = new int;
  checked_delete(i);

  // not this
  T* t = 0;
  checked_delete(t);

}
