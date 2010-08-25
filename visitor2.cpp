#include "study.hpp"

struct D1;
struct D2;

struct BVisitor 
{
  virtual void visit(D1& d) = 0;
  virtual void visit(D2& d) = 0;
};

struct B {   
  virtual void foo() = 0;
  virtual void accept(BVisitor& bv) = 0;
};

template <typename Derived, typename Base, typename Visitor>
struct visitable : Base 
{
  virtual void accept(Visitor& v) 
  {
    v.visit(static_cast<Derived&>(*this));
  }
};

struct D1 : visitable<D1, B, BVisitor> { };

struct D2 : visitable<D1, B, BVisitor> { };

struct ShowVisitor : BVisitor 
{
  void visit(D1& d) { SHOW(); }
  void visit(D2& d) { SHOW(); }
};


int main() 
{
  ShowVisitor sv;
  BVisitor& bv = sv;

  D1 d1;
  D2 d2;
  B& b1 = d1;
  B& b2 = d2;

  b1.accept(bv);
  b2.accept(bv);

  return 0;
}
