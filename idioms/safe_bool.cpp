

#include "study.hpp"

class testable {

  int actual;

  // bool type is pointer to member function
  // returning void and taking no arguments
  typedef void (*bool_type)();

  // this is a dummy function of that type
  static void yup_its_true() { }

  // option 2:
  // pointer to data member of type int
  // typedef int* testable::* bool_type;
  // then you'd use ptr-to-actual, above


public:

  testable(int i) : actual(i) { }

  operator bool_type() const
  {
    return actual != 7 ? 0 : &yup_its_true;
  }

};


int main()
{
  testable t1(3), t2(7);


  if (t1)
    std::cout << "t1 TRUE\n";
  else
    std::cout << "t1 FALSE\n";

  if (t2)
    std::cout << "t2 TRUE\n";
  else
    std::cout << "t2 FALSE\n";

}
