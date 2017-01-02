#include "util/study.hpp"

struct MO {
  std::string name;

  MO() = default;
  MO(MO&& rhs) = default;
  MO& operator=(MO&& rhs) = default;

  MO(const MO& rhs) = delete;
  MO& operator=(const MO& rhs) = delete;
};

int main(int, char**) {

  std::vector<MO> mov;
  mov.emplace_back();
  mov.emplace_back();
  mov.emplace_back();
  MO mymo;
  mov[1] = std::move(mymo);

  // MO othermo(mymo); // nope, explicitly marked deleted
  MO othermo;
  //  othermo = mymo; // nope, explicitly marked deleted
  std::swap(mymo, othermo); // ok, this happens strictly through moves
}
