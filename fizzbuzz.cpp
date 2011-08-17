#include <iostream>

template <bool> 
struct impl 
{
  template <typename T> impl(const T)   { }
};

template <> 
struct impl<true> 
{
  template <typename T> impl(const T t) { std::cout << t; }
};

template <int N = 100> 
struct fizzbuzz : fizzbuzz<N-1>
{
  typedef impl<N%3 == 0> Fizz;
  typedef impl<N%5 == 0> Buzz;
  typedef impl<N%3 != 0 && N%5 != 0> Number;

  fizzbuzz();
};

template <>
struct fizzbuzz<0> 
{
  fizzbuzz() { }
};

template <int N>
fizzbuzz<N>::fizzbuzz() 
{
  Number((const int)N);
  Fizz("Fizz");
  Buzz("Buzz");
  std::cout << "\n";
}


int main(int, char**)
{
  fizzbuzz<>();
}
