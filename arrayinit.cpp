#include "study.hpp"
#include <map>

struct C { 
  int x, y; 
  std::string s; 
  double d; 
};

int main() {
  
  C c = { 3, 4, std::string("booyah"), 1.111 };

  C ca[2] = { {5, 6, std::string("gunk"), 3.333 },
	      {7, 8, std::string("hoop"), 4.444 } };

  std::cout << c.x << c.y << c.s << c.d << "\n";
  std::cout << ca[1].x << ca[1].y << ca[1].s << ca[1].d << "\n";

};
