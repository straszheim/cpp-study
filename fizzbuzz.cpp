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

template <int N = 100, 
          typename Fizz = impl<N%3 == 0>, 
          typename Buzz = impl<N%5 == 0>,
          typename Number = impl<N%3 != 0 && N%5 != 0> > 
struct fizzbuzz : fizzbuzz<N-1>
{
  fizzbuzz();
};

template <typename Fizz, typename Buzz, typename Number>
struct fizzbuzz<0, Fizz, Buzz, Number> 
{
  fizzbuzz() { }
};

template <int N, typename Fizz, typename Buzz, typename Number>
fizzbuzz<N, Fizz, Buzz, Number>::fizzbuzz() 
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
