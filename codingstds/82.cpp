#include "study.hpp"
#include <vector>
#include <algorithm>
#include <iterator>


void show(std::vector<int>& v) 
{
  std::cout << "size=" << v.size() << " cap=" << v.capacity() << "\n";
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
  std::cout << "\n";
}

int main() {

  std::vector<int> vi(10);
  vi[1] = 7;
  vi[3] = 7;

  show(vi);
  vi.resize(8);

  std::vector<int>(vi).swap(vi);
  show(vi);


  std::remove(vi.begin(), vi.end(), 7);
  show(vi);

  vi.erase(std::remove(vi.begin(), vi.end(), 7), vi.end());
  show(vi);

  std::cout << "done\n";
}
