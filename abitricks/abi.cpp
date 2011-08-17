#include <foo/abi.hpp>
#include <exception>

namespace foo {

  abi_checker::abi_checker(unsigned version)
  {
    if (version != abi_version)
      throw incompatible_version(version, abi_version);
  };

  incompatible_version::incompatible_version(unsigned c, unsigned r)
    : compiled_version(c), running_version(r)
  { }

  const char* incompatible_version::what() const throw() {
    return "Runtime version of foo is incompatible with the compiletime version of foo.  Check the contents of your runtime link path.";
  }

}
