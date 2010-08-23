#include "study.hpp"

struct Base 
{

  Base* clone() 
  {
    return clone_impl();
  }

  virtual void bang() = 0;
private:
  virtual Base* clone_impl() = 0;
};



template <typename D>
struct BaseCRTP : Base {

  Base* clone_impl() {
    return new D(*(static_cast<D*>(this)));
  }

};



struct D1 : BaseCRTP<D1>
{
  void bang() {
    SHOW();
  }
};

struct D2 : BaseCRTP<D2>
{
  void bang() {
    SHOW();
  }
};



int main() {

  Base* b1 = new D1;
  b1->bang();
  Base* b1a = b1->clone();
  b1a->bang();

  Base* b2 = new D2;
  b2->bang();
  Base* b2a = b2->clone();
  b2a->bang();
}
