/* 
  what are the three forms of operator new
*/


// plain old new -- replaceable
void* ::operator new(std::size_t size) throw (std::bad_alloc);

// nothrow new   -- replaceable
void* ::operator new(std::size_t size, const std::nothrow_t&) throw ();

// placement new -- not replaceable.
void* ::operator new(std::size_t size, void*) throw ();


// example uses:

FastMemory memmgr;
T* t = new (memmgr) T;  // calls new (std::size_t, FastMemory&)

new (42, 1.1, "foo") T;  // calls new (std::size_t, int, double, const char*)

new (std::nothrow) T;   /* calls std or usersupplied 
			   new(std::size_t, std::nothrow_t&)
			*/

