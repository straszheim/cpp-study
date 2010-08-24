#include "study.hpp"

struct my_exception : verbose<my_exception> { };

int main() {
  std::cout << "****** start:  throw a temporary. ******\n";

  try {
    std::cout << "trying...\n";
    throw my_exception();  // this is a temporary that *can* bind to 
    // the nonconst reference in the catch
  } catch (my_exception& e) {
    std::cout << "catchy stuff...\n";
  }
  std::cout << "catch exited\n";

  std::cout << "****** rethrow by name\n";
  // rethrow.  it is named, a copy will be made
  try {
    std::cout << "outer try\n";
    try {
      std::cout << "inner try\n";
      throw my_exception();
    } catch (my_exception& e) {
      std::cout << "inner catch, rethrowing by name\n";
      throw e;
    }
    std::cout << "YOU NEVER SEE THIS\n";
  } catch (my_exception& e) {
    std::cout << "outer catch\n";
  }
  std::cout << "main()\n";

  std::cout << "****** rethrow unnamed ******\n";
  // rethrow.  it is named, a copy will be made
  try {
    std::cout << "outer try\n";
    try {
      std::cout << "inner try\n";
      throw my_exception();
    } catch (my_exception& e) {
      std::cout << "inner catch, rethrowing by name\n";
      throw;
    }
    std::cout << "YOU NEVER SEE THIS\n";
  } catch (my_exception& e) {
    std::cout << "outer catch\n";
  }
  std::cout << "main()\n";



}
