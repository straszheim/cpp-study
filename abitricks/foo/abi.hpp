#pragma once
#include <stdexcept>

namespace foo {
  // exception to be thrown in case of detected incompatiblity
  struct incompatible_version : std::exception
  {
    unsigned compiled_version, running_version;
    incompatible_version(unsigned compiledwith, unsigned runningwith);
    virtual const char* what() const throw();
  };
  bool abi_version_is_okay(unsigned);

  namespace {
    const unsigned abi_version = ABI_VERSION;
#ifndef foo_EXPORTS
    const bool abi_version_okay__ = abi_version_is_okay(abi_version);
#endif
  }
}






