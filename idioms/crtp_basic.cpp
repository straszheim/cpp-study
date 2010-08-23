#include "study.hpp"

template <class D>
struct B
{
  // like a nothing-virtual NVI pattern
  void iface() 
  {
    static_cast<D*>(this)->impl();
  }

  static void static_iface()
  {
    D::static_impl();
  }

private:

  void impl()
  {
    SHOW() << "base impl\n";
  }

  static void static_impl()
  {
    SHOW() << "base static impl\n";
  }

};


struct D1 : B<D1>
{
private:
  void impl() {
    SHOW() << "derived impl\n";
  }
  friend class B<D1>;
};


struct D2 : B<D2>
{
private:
  static void static_impl() {
    SHOW() << "derived static impl\n";
  }
  friend class B<D2>;
};



int main() {

  D1 d1;
  d1.iface();
  D1::static_iface();

  D2 d2;
  d2.iface();
  D2::static_iface();

}
