#include "study.hpp"

#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/function_types/function_arity.hpp>
#include <boost/function_types/function_type.hpp>
#include <boost/function_types/components.hpp>
#include <boost/mpl/at.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/fusion/include/cons.hpp>
#include <boost/fusion/include/push_back.hpp>
#include <boost/fusion/include/invoke.hpp>

#include <cmath>
#include <vector>

using boost::any;
using boost::any_cast;
using boost::function;
using boost::result_of;

namespace ft = boost::function_types;

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

template <typename T>
struct converter
{
  typedef T result_type;

  T operator()(const any& arg)
  { 
    return boost::any_cast<T>(arg);
  }
};


template <typename R, typename U>
struct converter<R(U)> {
  typedef typename boost::result_of<R(U)>::type result_type;

  result_type operator()(const any& a) {
    U u = boost::any_cast<U>(a);
    return R()(u);
  }
};

struct caller 
{
  virtual any operator()(const std::vector<any>& v) = 0;

  virtual ~caller();
};

caller::~caller() { }


template <typename Signature,
	  unsigned Arity = ft::function_arity<Signature>::value>
struct caller_impl : caller
{
  typedef typename ft::parameter_types<Signature>::type params_t;

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
      arg_t this_arg = converter<arg_t>()(*iter);
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
      std::cout << "now i'd call it with\n";
      std::cout << name_of(typeid(accum)) << "now i'd call it?\n";
      return any(fusion::invoke(callable, accum));
    }
  };

};

template <typename Fn>
caller* 
def(Fn f) 
{
  return new caller_impl<typename ft::function_type<typename ft::components<Fn>::type>::type>(f);
}

struct MyConverter 
{
  typedef std::string result_type;

  template <typename T>
  result_type operator()(const T& t) {
    return "[[[" + boost::lexical_cast<std::string>(t)+ "]]]";
  }
};

int main()
{
  std::vector<any> times_args;
  times_args.push_back(std::string("<<THISSTRING>>"));
  times_args.push_back(2u);
  
  caller* su = def<std::string(MyConverter(float), unsigned)>(times); 
  any a = (*su)(times_args);
  std::cout << "result is " << any_cast<std::string>(a) << "\n";


  std::vector<any> mag_args;
  mag_args.push_back(1.0f);
  mag_args.push_back(1.0f);
  mag_args.push_back(1.0f);

  caller* fff = def<float(float, float, float)>(magnitude);
  a = (*fff)(mag_args);
  std::cout << "result is " << any_cast<float>(a) << "\n";


  //  std::cout << "result of is " << name_of<result_of<converter(bool)>::type>() << "\n";

}
