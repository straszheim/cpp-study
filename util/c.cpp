#include <iostream>
#include "util/c.hpp"

int C::constructions = 0;
int C::destructions = 0;
int C::moveconstructs = 0;
int C::copies = 0;
int C::copyassigns = 0;
int C::moveassigns = 0;
int C::population = 0;

void C::report(const char* file, int line, const char* commonname) {
  std::cout << file << ":" << line
            << " \"" << name << "\""
            << " aka \"" << commonname << "\""
            << " constr: " << constructions
            << "  destr: " << destructions
            << "  moves: " << moveconstructs
            << " copies: " << copies
            << " cassgn: " << copyassigns
            << " massgn: " << moveassigns
            << "    pop: " << population
            << "\n";
}

#define SHOW() do { std::cout << __PRETTY_FUNCTION__ << " \'" << name << "\'\n"; } while(false)

C::C(std::string name_) : name(name_) {
  constructions++;
  population++;
  SHOW();
}

C::~C() {
  destructions++;
  population--;
  SHOW();
}

C::C(const C& rhs)
{
  name = rhs.name;
  copies++;
  population++;
  SHOW();
}

C::C(C&& rhs) {
  name = std::move(rhs.name);
  rhs.name = "MOVECONSTRUCTED_FROM";
  moveconstructs++;
  population++;
  SHOW();
}

C& C::operator=(const C& rhs) {
  name = rhs.name;
  copyassigns++;
  SHOW();
  return *this;
}

C& C::operator=(C&& rhs) {
  name = std::move(rhs.name);
  rhs.name = "MOVEASSIGNED_FROM";
  moveassigns++;
  SHOW();
  return *this;
};


