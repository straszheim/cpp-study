#include "study.hpp"
#include <map>

#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

using namespace boost::phoenix;
using namespace boost::phoenix::arg_names;

int main() {
  
  int seven=7;
  int result;
  (ref(result) = arg1)(seven);
  std::cout << result << "\n";  

};
