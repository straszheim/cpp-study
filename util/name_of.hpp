#ifndef PLUGINLIB_NAME_OF_HPP_INCLUDED
#define PLUGINLIB_NAME_OF_HPP_INCLUDED

#include <typeinfo>
#include <string>

std::string name_of(const std::type_info &ti);

template <typename T>
std::string name_of()
{
  return name_of(typeid(T));
}

#endif
