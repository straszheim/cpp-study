#pragma once
#include <stdexcept>

namespace foo {
  const static unsigned abi_version = ABI_VERSION;

  struct incompatible_version : std::exception {
    unsigned compiled_version, running_version;
    incompatible_version(unsigned compiledwith, unsigned runningwith);
    virtual const char* what() const throw();
  };

  struct abi_checker {
    abi_checker(unsigned version);
  };

  namespace {
    abi_checker checker(abi_version);
  }
}




