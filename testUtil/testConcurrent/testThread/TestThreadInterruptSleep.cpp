#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadInterruptSleep() {
  TimeWatcher watcher = createTimeWatcher();

  while(1) {
    bool isInterrupt = false;
    Thread t = createThread([&isInterrupt]{
      try {
        st(Thread)::sleep(200);
      } catch(...) {
        isInterrupt = true;
      }
    });
    t->start();
    usleep(100*1000);
    t->interrupt();
    t->join();
    if(!isInterrupt) {
      TEST_FAIL("[Thread Test {interruptSleep()} case1]");
    }
    break;
  }

  while(1) {
    Thread t = createThread([]{
      try {
        st(Thread)::sleep(100);
      } catch(...) {
      }
    });
    t->start();
    watcher->start();
    t->join();
    long result = watcher->stop();

    if(result < 100 || result > 105) {
      TEST_FAIL("[Thread Test {interruptSleep()} case2]");
    }
    break;
  }
  
  while(1) {
    bool isInterrupt = false;
    Thread t = createThread([&isInterrupt]{
      try {
        usleep(100*1000);
        st(Thread)::sleep(200);
      } catch(...) {
        isInterrupt = true;
      }
    });
    t->start();
    usleep(100);
    t->interrupt();
    t->join();
    if(!isInterrupt) {
      TEST_FAIL("[Thread Test {interruptSleep()} case3]");
    }
    break;
    
  }
  TEST_OK("[Thread Test {interruptSleep()} case100]");


}
