#include "study.hpp"


#include <boost/thread.hpp>

boost::recursive_mutex mtx;


void locky(int i)
{
  std::cout << "start lock " << i << "\n";
  if (i > 0)
    {
      boost::recursive_mutex::scoped_lock sl(mtx);
      usleep(100 * 1000);
      locky(i-1);
    }
  usleep(100*1000);
  std::cout << "finish lock " << i << "\n";
}

int main(int, char**)
{
  SHOW();
  {
    boost::recursive_mutex::scoped_lock ol(mtx);
    locky(10);
  }
  boost::thread th(boost::bind(&locky, 10));
  usleep(10000);
  std::cout << "try otherthread lock:\n";
  boost::recursive_mutex::scoped_lock ol2(mtx);
  std::cout << "got otherthread lock:\n";

  th.join();
}
