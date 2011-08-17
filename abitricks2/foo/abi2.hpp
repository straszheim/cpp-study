#pragma once
#include <stdexcept>
#warning abi2
namespace foo {
  bool abi_version_is_14();
  namespace {
    const static bool version_okay = abi_version_is_14();
  }
}






