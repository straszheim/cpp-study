
#include "study.hpp"
#include <boost/mpl/bool.hpp>
#include <vector>

  template <typename T> struct hold { };

  template <typename T>
  void do_sfn(hold<T>, float f)
  {
    SHOW();
    T::sfn(f);
  }

  template <typename Cell, typename T0, typename T1=void, typename T2=void, typename T3=void>
  struct interface;

  template <typename Cell, typename T0>
  struct interface<Cell, T0, void, void>
  {
    friend void do_sfn(hold<Cell>, float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      do_sfn(hold<T0>(), f);
      SHOW();
    }
  };

  template <typename Cell, typename T0, typename T1>
  struct interface<Cell, T0, T1, void>
  {
    friend void do_sfn(hold<Cell>, float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      do_sfn(hold<T0>(), f);
      do_sfn(hold<T1>(), f);
      SHOW();
    }
  };

  template <typename Cell, typename T0, typename T1, typename T2>
  struct interface<Cell, T0, T1, T2>
  {
    friend void do_sfn(hold<Cell>, float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      do_sfn(hold<T0>(), f);

      do_sfn(hold<T1>(), f);
      do_sfn(hold<T2>(), f);
      SHOW();
    }
  };

struct S 
{
  static void sfn(float f) { SHOW(); }
};

struct TFace 
{
  static void sfn(float f) { SHOW(); }
};

struct U
{ 
  static void sfn(float f) { SHOW(); }
};

struct V : interface<V, U> 
{ 
  static void sfn(float f) { SHOW(); }
};

struct X : interface<X, V, TFace, S>
{
  static void sfn(float f) { SHOW(); }
};

template <typename T>
void doit(float f)
{
  do_sfn(hold<T>(), f);
}

int main()
{
  doit<X>(13);
}
