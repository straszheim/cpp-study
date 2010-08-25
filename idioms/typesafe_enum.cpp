#include "study.hpp"

template<typename def, typename inner = typename def::type>
class safe_enum : public def
{
  typedef typename def::type type;
  inner val;
 
public:
 
  safe_enum(type v) : val(v) {}
  inner underlying() const { return val; }
 
  bool operator == (const safe_enum & s) const { return this->val == s.val; }
  bool operator != (const safe_enum & s) const { return this->val != s.val; }
  bool operator <  (const safe_enum & s) const { return this->val <  s.val; }
  bool operator <= (const safe_enum & s) const { return this->val <= s.val; }
  bool operator >  (const safe_enum & s) const { return this->val >  s.val; }
  bool operator >= (const safe_enum & s) const { return this->val >= s.val; }
  
  friend std::ostream& operator<<(std::ostream& os, const safe_enum& se)
  {
    return os << se.val;
  }

};
 
struct color_def {
  enum type { red, green, blue };
};
typedef safe_enum<color_def> color;
 
struct shape_def {
  enum type { circle, square, triangle };
};
typedef safe_enum<shape_def, unsigned char> shape; // unsigned char representation
 
int main(void)
{
  color c = color::red;
  std::cout << "colors: " << color::red << color::blue << color::green << "\n";
  std::cout << "shapes: " << shape::circle << shape::square << shape::triangle << "\n";
  // bool flag = (c >= shape::triangle); // Compiler error.
  bool flag = color::red < shape::circle;
}
