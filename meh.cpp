#include <iostream>
#include <boost/any.hpp>

int main()
{
  boost::any a = 13;
  int& i = boost::any_cast<int&>(a);
  std::cout << i << " <- okay\n";
  const int& ic = boost::any_cast<const int&>(a);
  std::cout << ic << " <- okay\n";

  const int* icp = boost::unsafe_any_cast<const int>(&a);

  std::cout << *icp << " <- still okay\n";
  std::string& s = boost::any_cast<std::string&>(a);
  std::cout << "throw before this line\n";
}

