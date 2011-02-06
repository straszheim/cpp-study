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
  vi[0] = 9;
  vi[1] = 8;
  vi[2] = 7;
  vi[3] = 6;
  vi[4] = 5;
  vi[5] = 4;
  vi[6] = 3;
  vi[7] = 2;
  vi[8] = 1;

  std::cout << "initial vector...\n";
  show(vi);


  std::cout << "resize 8, swap with itself...\n";
  vi.resize(8);
  std::vector<int>(vi).swap(vi);
  show(vi);


  std::cout << "remove 7...\n";
  std::vector<int>::iterator iter = std::remove(vi.begin(), vi.end(), 7);
  std::cout << "iter at " << std::distance(vi.begin(), iter) << "\n";
  show(vi);

  std::cout << "erase (w/ iter from remove)...\n";
  vi.erase(iter, vi.end());
  show(vi);

  std::cout << "resize doesn't change capacity\n";
  vi.resize(0);
  show(vi);

  std::cout << "done\n";
}
