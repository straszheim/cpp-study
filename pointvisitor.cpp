#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>
#include <stdexcept>
#include <string>
#include <cassert>
#include "study.hpp"
#include <map>

struct PointCloudXYZ 
{ 
  void foo(){SHOW();}
};

struct PointCloudXYZRGB 
{
  void foo(){SHOW();}
};

// pcl's filter
template <typename PointType>
struct VoxelGrid 
{

  void set_threshold(double) { SHOW(); }
  void filter(const PointType& pt)
  {
    SHOW();
  };

private:

  typedef PointType PointCloud;
};

template <template <class> class Filter, typename PointType>
void munge2(Filter<PointType>)
{
  SHOW();
}

template <typename T>
void munge(VoxelGrid<T>)
{
  SHOW();
}

template <typename T>
void showme_this(T)
{
  SHOW();
}


// hacky pcl workaround, but not as bad as #define private public
// my new fighting style is unstoppable
template <typename Filter, typename PointType>
struct filter_takes_point_trait : boost::false_type { };


template <template <class> class Filter, typename PointType>
struct filter_takes_point_trait<Filter<PointType>, PointType> : boost::true_type { };


template <typename PointType>
struct PassThrough
{
  typedef PointType PointCloud;

  void bar() { }
  void filter(const PointType& pt)
  {
    SHOW();
  };
};

typedef boost::variant< PointCloudXYZ, PointCloudXYZRGB > point_variant_t;
typedef boost::variant< VoxelGrid<PointCloudXYZ>, VoxelGrid<PointCloudXYZRGB> > filter_variant_t;

/////////////////////////////////////////////////////////////

//template <typename PointType>
//void configure(VoxelGrid<PointType>& vg) { SHOW(); }

//void configure(PassThrough& vg) { SHOW(); }

struct PointCloud {

  struct holder_base {
    virtual point_variant_t make_variant() = 0;
  };

  template <typename T>
  struct holder : holder_base
  {
    T t;
    holder(T t_) : t(t_) { }

    point_variant_t make_variant()
    {
      return point_variant_t(t);
    }
    
    

  };

  boost::shared_ptr<holder_base> held;

  template <typename T>
  PointCloud(T t_)
  {
    held.reset(new holder<T>(t_));
  }

  point_variant_t make_variant()
  {
    return held->make_variant();
  }

};

template <template <class> class FilterPolicy>
struct make_filter_variant : boost::static_visitor<filter_variant_t>
{
  template <typename PointType>
  filter_variant_t operator()(const PointType& p) const
  {
    return filter_variant_t(FilterPolicy<PointType>());
  }
};

struct showme : boost::static_visitor<void>
{
  template <typename T>
  void operator()(const T& p) const
  {
    SHOW();
  }
  template <typename Filter, typename Point>
  void operator()(const Filter& f, const Point& p) const
  {
    SHOW();
  }
};

struct filter_dispatch : boost::static_visitor<void>
{

  template <typename Filter, typename PointType>
  void 
  operator()(Filter& f, PointType& p) const
  {
    //    impl(f, p, boost::is_same<point_type_trait<typename Filter>::type, PointType>());
    impl(f, p, filter_takes_point_trait<Filter, PointType>());
  }

  template <typename Filter, typename PointType>
  void impl(Filter& f, PointType& p, boost::true_type) const
  {
    f.filter(p);
    std::cout << "SAME!\n";
  }

  template <typename Filter, typename PointType>
  void impl(Filter& f, PointType& p, boost::false_type) const
  {
    throw std::runtime_error("types aren't the same, you are doing something baaaaaad");
  }

  /*
  // IMPL2:  enable_if
  template <typename Filter, typename PointType>
  typename boost::enable_if<boost::is_same<typename Filter::PointCloud, PointType> >::type
  operator()(Filter& f, PointType& p) const
  {
    f.filter(p);
    std::cout << "SAME!\n";
  }

  template <typename Filter, typename PointType>
  typename boost::disable_if<boost::is_same<typename Filter::PointCloud, PointType> >::type
  operator()(Filter& f, PointType& p) const
  {
    std::cout << "NOT SAME!\n";
  }
  */
};

struct VoxelGridParams { float thresh; };
struct configurator : boost::static_visitor<void>
{
  VoxelGridParams& vp;
  configurator(VoxelGridParams& vp_) : vp(vp_) { }

  template <typename PointType>
  void operator()(VoxelGrid<PointType>& filter) const
  {
    // use VoxelGridParams
    filter.set_threshold(vp.thresh); // setup specific to Voxelgrid but not Voxelgrid<T>
  }
};


int main() {
  // declare_params

  // declare_io

  std::cout << boost::is_same<bool, int>::value << "\n";

  // configure
  VoxelGridParams vp;
  vp.thresh = 17.0; // get from tendril
  bool configured = false; // set that we've configured the filter to false


  PointCloudXYZ pc1;
  //------------------------------------------------------------

  PointCloud pc_erased_1(pc1);
  point_variant_t pvar = pc_erased_1.make_variant();

  filter_variant_t fv;
  // process, 5 times
  for (unsigned j=0; j<5; ++j)
    {
      if (! configured) {
        fv = boost::apply_visitor(make_filter_variant<VoxelGrid>(), pvar);
        boost::apply_visitor(configurator(vp), fv);
        configured = true;
      }
      boost::apply_visitor(filter_dispatch(), fv, pvar);
    }

  boost::apply_visitor(showme(), fv);

  boost::apply_visitor(showme(), fv, pvar);
  


  //  VoxelGrid<PointCloudXYZ> filterinst;
  //  filter_dispatch<VoxelGrid<PointCloudXYZ> > filterer(filterinst);

  //  boost::apply_visitor(filterer, pvar);

  //VoxelGrid<PointCloudXYZ> vg1;
  //vg1.filter(pc1);


};
