#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <future>
#include <boost/asio.hpp>
#include <boost/array.hpp>

#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "study.hpp"

using namespace boost::asio;
using namespace std;
using ip::udp;

struct banger {

  boost::asio::io_service serv;
  boost::asio::deadline_timer dt;
  boost::asio::io_service::work work;
  std::promise<int> prom;

  banger(int howlong) :dt(serv, boost::posix_time::seconds(howlong)), work(serv) { }

  std::future<int> doit()
  {
    BARK();
    auto cb = [&](const boost::system::error_code&) {
      std::cout << "CB!\n";
      prom.set_value(13);
    };
    dt.async_wait(cb);
    return prom.get_future();
  }
};

int main()
{
  banger b(1);
  std::thread runner([&b]() { b.serv.run(); });
  BARK();

  std::future<int> fi = b.doit();
  std::this_thread::sleep_for(2s);
  std::cout << "ready to read...\n";
  std::cout << "reading int from future = " << fi.get() << "\n";

  runner.join();
  return 0;
}
