/*
  compiler starts in current scope (member functions of D) and
  searches "continuing "outward' until it finds anything whose name
  matches, then it stops.  *then* it does overload resolution and
  applies access rules.  

  it has to work this way: of course a member function that requires
  an argument conversion should be called before a freestanding
  function that is a perfect match.


  Next question:  how do you fix?  two ways.

*/
