//
//  name the different memory areas, performance characteristics
//  and lifetime of objects that live there
//
#include "study.hpp"

int main() { }

/*

  const data:  whole lifetime of program, UB if you try to modify, 

  stack: (de)alloc only involves moving stack pointer around, so
  faster than dynamic storage, objs constructed @ definition point and
  destroyed when leave scope,

  frestore and heap are same region of memory, distinction is in the
  compiler.  But they're different: you can't free() memory you've
  newed, or delete memory you've malloc()ed  

  freestore: mgd by new/delete.  you can get at the memory with a
  void* but you can't use the object until it has been constructed or
  after it has been destroyed.

  heap: msd by malloc/free.  new/delete might be impled in terms of
  new/delete.  You can placement-new and explicit destruct in this
  region.

  global/static: allocated at program startup, might not be
  initialized until after program has begun executing (e.g. static
  variable in a function).  order of init across trans units is
  undefined.


  it is specified that you can't implement malloc/free in terms of
  new/delete.  other way round is typical.


*/
