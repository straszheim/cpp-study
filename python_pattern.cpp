#include "study.hpp"

#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/function_types/function_arity.hpp>
#include <boost/mpl/at.hpp>

#include <boost/fusion/include/cons.hpp>
#include <boost/fusion/include/push_back.hpp>
#include <boost/fusion/include/invoke.hpp>

#include <cmath>
#include <vector>

using boost::any;
using boost::any_cast;
using boost::function;
using boost::function_types::parameter_types;
using boost::function_types::function_arity;
namespace mpl = boost::mpl;
namespace fusion = boost::fusion;

float magnitude(float x, float y, float z)
{
  SHOW() << "MAGNITUDE!\n";
  return sqrt(x*x + y*y + z*z);
}

std::string times(std::string what, unsigned n)
{
  SHOW() << "TIMES!\n";
  std::string rv;
  for (unsigned j=0; j<n; j++)
    {
      rv += what;
    }
  return rv;
}


struct caller 
{
  virtual any operator()(const std::vector<any>& v) = 0;

  virtual ~caller();
};

caller::~caller() { }


template <typename Signature,
	  unsigned Arity = function_arity<Signature>::value>
struct caller_impl : caller
{
  typedef typename parameter_types<Signature>::type params_t;

  function<Signature> fn;

  caller_impl(const function<Signature>& fn_) : fn(fn_) { }

  any operator()(const std::vector<any>& v) 
  { 
    SHOW() << name_of<params_t>() << "\n";
    return invoker<>::apply(v.begin(), fn, fusion::nil());
  }


  template <int ArgN = 0, typename unused = void>
  struct invoker {
    typedef typename mpl::at_c<params_t, ArgN>::type arg_t;
    
    template <typename Accum, typename Callable>
    static inline any 
    apply(std::vector<any>::const_iterator iter,
	  const Callable& callable,
	  Accum const& accum)
    {
      arg_t this_arg = boost::any_cast<arg_t>(*iter);
      std::cout << "ARG=" << this_arg << " (" << name_of<arg_t>() << ")\n";
      return invoker<ArgN+1>::apply(++iter, callable, fusion::push_back(accum,
							      this_arg));
    }

  };
    
  template <typename unused>
  struct invoker<Arity, unused>
  {
    typedef typename mpl::at_c<params_t, Arity>::type arg_t;
    template <typename Callable, typename Accum>
    static inline any 
    apply(std::vector<any>::const_iterator iter,
	  Callable const& callable,
	  Accum const& accum)
    {
      //      arg_t this_arg = boost::any_cast<arg_t>(*iter);
      std::cout << "now i'd call it with\n";
      std::cout << name_of(typeid(accum)) << "now i'd call it?\n";
      return any(fusion::invoke(callable, accum));
    }
  };

};

int main()
{
  std::vector<any> times_args;
  times_args.push_back(std::string("<<THISSTRING>>"));
  times_args.push_back(2u);
  
  caller* su = new caller_impl<std::string(std::string, unsigned)>(times);
  any a = (*su)(times_args);
  std::cout << "result is " << any_cast<std::string>(a) << "\n";


  std::vector<any> mag_args;
  mag_args.push_back(1.0f);
  mag_args.push_back(1.0f);
  mag_args.push_back(1.0f);

  caller* fff = new caller_impl<float(float, float, float)>(magnitude);
  a = (*fff)(mag_args);
  std::cout << "result is " << any_cast<float>(a) << "\n";
}
