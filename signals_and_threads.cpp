#include "study.hpp"
#include <iostream>
#include <signal.h>
#include <errno.h>

bool shutdown = false;

void handle_sigint(int s)
{
  SHOW() << " => " << s << "\n";
}



int main(int, char**)
{
  struct sigaction sa, oldsa;
  sa.sa_handler = &handle_sigint;
  sa.sa_flags = SA_RESTART;
  sigaction(SIGINT, &sa, &oldsa);
  /*
    signal(SIGINT, &handle_sigint);
  */
  while(!shutdown)
    {
      std::cout << "not shutdown...\n";
      char buf[255];
      int j = read(0, buf, 25);
      if (j<0)
        std::cout << "errno=" << errno << "\n";
      std::cout << "read j=" << j << "\n";
      write(0, buf, j);
    }

}
