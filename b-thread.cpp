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

template <typename Mutex>
void lockwhile(boost::function<void()> h, Mutex& m)
{
  typename Mutex::scoped_lock lock(m);
  h();
}


int main(int, char**)
{
  SHOW();
  
  boost::function<void()> fn = boost::bind(&locky, 10);
  boost::thread th(boost::bind(&lockwhile<boost::recursive_mutex>, fn, boost::ref(mtx)));
  usleep(10000);
  
  boost::recursive_mutex::scoped_lock triedlock(mtx, boost::defer_lock);
  std::cout << "try lock = " << triedlock.try_lock() << "\n";
  std::cout << "try lock = " << triedlock.try_lock() << "\n";
  std::cout << "try lock = " << triedlock.try_lock() << "\n";
  std::cout << "owns lock = " << triedlock.owns_lock() << "\n";
  std::cout << "get lock in other thread\n";
  boost::recursive_mutex::scoped_lock otherlock(mtx);
  std::cout << "GOT\ntrying again...\n";
  std::cout << "try lock = " << triedlock.try_lock() << "\n";
  std::cout << "owns lock = " << triedlock.owns_lock() << "\n";
  std::cout << "wait and join\n";
  th.join();

}
