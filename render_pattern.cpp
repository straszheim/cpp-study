#include "study.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <map>

using boost::shared_ptr;
using boost::dynamic_pointer_cast;
using boost::make_shared;

struct Base 
{ 
  virtual ~Base();
};

Base::~Base() { }

typedef shared_ptr<Base> BasePtr;

struct D1 : Base { };
typedef shared_ptr<D1> D1Ptr;

struct D2 : Base { };
typedef shared_ptr<D2> D2Ptr;

struct D3 : Base { };
typedef shared_ptr<D3> D3Ptr;



struct RenderBase {
  virtual ~RenderBase();
  
  virtual bool can_render(BasePtr) = 0;
  virtual bool render(BasePtr) = 0;
};
RenderBase::~RenderBase() { }
typedef shared_ptr<RenderBase> RenderBasePtr;

template <typename RenderImpl,
	  typename RenderedT>
struct RenderDispatch : RenderBase
{
  typedef shared_ptr<RenderedT> RenderedPtr;

  bool can_render(BasePtr bp)
  {
    return dynamic_pointer_cast<RenderedT>(bp);
  }

  bool render(BasePtr bp)
  {
    RenderedPtr rp(dynamic_pointer_cast<RenderedT>(bp));
    assert(rp);
    this->prerender(rp);
    this->postrender(rp);
    return true;
  }

private:

  virtual bool prerender(RenderedPtr) = 0;
  virtual bool postrender(RenderedPtr) = 0;
};

struct RenderD1 : RenderDispatch<RenderD1, D1>
{
  bool prerender(D1Ptr dp) { SHOW(); return true; }
  bool postrender(D1Ptr dp) { SHOW(); return true; }
};

struct RenderD2 : RenderDispatch<RenderD2, D2>
{
  bool prerender(D2Ptr dp) { SHOW(); return true; }
  bool postrender(D2Ptr dp) { SHOW(); return true; }
};

struct RenderD3 : RenderDispatch<RenderD3, D3>
{
  bool prerender(D3Ptr dp) { SHOW(); return true; }
  bool postrender(D3Ptr dp) { SHOW(); return true; }
};


int main()
{
  std::map<std::string, BasePtr> stuff;

  stuff["dee_one"] = make_shared<D1>();
  stuff["dee_two"] = make_shared<D2>();
  stuff["dee_three"] = make_shared<D3>();

  std::map<std::string, RenderBasePtr> renderers;
  renderers["rend_one"] = make_shared<RenderD1>();
  renderers["rend_two"] = make_shared<RenderD2>();
  renderers["rend_three"] = make_shared<RenderD3>();

  for (std::map<std::string, BasePtr>::iterator iter = stuff.begin(),
	 end = stuff.end();
       iter != end;
       ++iter)
    {
      for (std::map<std::string, RenderBasePtr>::iterator ri = renderers.begin(),
	     rend = renderers.end();
	   ri != rend;
	   ++ri)
	{
	  if (ri->second->can_render(iter->second))
	    ri->second->render(iter->second);
	}
    }


}
