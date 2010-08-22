//given

#include "study.hpp"
#include <vector>

template <typename T>
void munge(std::vector<T>& v)
{
  SHOW() << "MAIN TEMPLATE\n";
}


template <>
void munge(std::vector<float>& fv)
{
  SHOW() << "EXPLICITLY SPECIALIZED\n";
}


template <typename T, typename U>
struct C 
{
  C() { SHOW() << "MAIN TEMPLATE\n"; }
};

template <typename T>
struct C<T, int>
{
  C() { SHOW() << "PARTIAL SPEC\n"; }
};

int main()
{
  std::vector<int> vi;
  munge(vi);

  std::vector<float> vf;
  munge(vf);

  C<int, bool> c;
  C<float, int> cspec;

}
