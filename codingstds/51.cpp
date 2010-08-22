/*

  destructors, deallocation, and swap

  * you can't use types whose destructors might throw in the std library

  * in transactional programming you need to back out if things screw up
  (destruct/dealloc) or commit if things are okay (swap)

  * if somebody's destructor throws while an exception is being
  propagated, std::terminate is called and you're dead

  given N whose destructor might throw:

  * can't inst. N in a scope that might be exited via exception
  
  * classes w/ N members are hard to use safely
  
  * can't reliably create global or static ones either:  you can't catch 
  those exceptions

  * can't create arrays of them: what if the 4th out of 10 Ns
  constructor throws, then a destructor throws while cleaning up.

  * can't use them in std containers

*/
