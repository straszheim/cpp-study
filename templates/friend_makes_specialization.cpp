

#include "study.hpp"
#include <boost/mpl/bool.hpp>
#include <vector>

namespace invoke 
{
  using boost::mpl::true_;
  using boost::mpl::false_;

  typedef char true_type;
  struct false_type { true_type _[2]; };

  template <typename T> true_type  implements_interface(typename T::implements_interfaces *);
  template <typename T> false_type implements_interface(...);

  template <typename T> struct hold { };

  template <typename Cell, typename T0, typename T1=void, typename T2=void, typename T3=void>
  struct interface;


  template <typename Cell, typename T0, typename T1, typename T2>
  void invoke_many(hold<interface<Cell, T0, T1, T2> >, float f)
  {
    interface<Cell, T0, T1, T2>::sfn(f);
  }

  template <typename T>
  void invoke_single(hold<T>, float f)
  {
    SHOW();
    T::sfn(f);
  }


  template <typename T, int Size = sizeof(implements_interface<T>(0))>
  struct interfaces_dispatch
  { 
    static void go(float f) {
      invoke_many(hold<T>(), f);
    }
  };

  template <typename T>
  struct interfaces_dispatch<T, sizeof(false_type)>
  {
    static void go(float f) {
      invoke_single(hold<T>(), f);
    };
  };

  template <typename T> struct type { };


  template <typename Cell, typename T0>
  struct interface<Cell, T0, void, void>
  {
    typedef true_ implements_interfaces;

    static void sfn(float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      T0::sfn(f);
      SHOW();
    }
  };

  template <typename Cell, typename T0, typename T1>
  struct interface<Cell, T0, T1, void>
  {
    typedef true_ implements_interfaces;

    static void sfn(float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      T0::sfn(f);
      T1::sfn(f);
      SHOW();
    }
  };

  template <typename Cell, typename T0, typename T1, typename T2>
  struct interface<Cell, T0, T1, T2>
  {
    typedef true_ implements_interfaces;

    static void sfn(float f) 
    {
      std::cout << "oh yes I am special\n";
      Cell::sfn(f);
      T0::sfn(f);
      T1::sfn(f);
      T2::sfn(f);
      SHOW();
    }
  };

}

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

struct V : invoke::interface<V, U> 
{ 
  static void sfn(float f) { SHOW(); }
};

struct X : invoke::interface<X, S>
{
  static void sfn(float f) { SHOW(); }
};

template <typename T>
void doit(float f)
{
  std::cout << "size=" << sizeof(invoke::implements_interface<T>(0)) << "\n";

  invoke::interfaces_dispatch<T>::go(f);
  //invoke::invoke_sfns(invoke::type<T>(), f);
}


int main()
{
  doit<S>(13);
  doit<X>(13);
}
