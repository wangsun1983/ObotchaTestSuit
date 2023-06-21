#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "HandlerThread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testHandlerLooperQuit() {
  //case 1
  while(1) {
    HandlerThread t = createHandlerThread();
    t->start();

    Handler t1 = createHandler(t->getLooper());
    int value = 100;
    TimeWatcher watcher = createTimeWatcher();
    t1->post([&]{
      value = 1;
    });

    usleep(1000*100);
    if(value != 1) {
      TEST_FAIL("[Handler Test Looper Quit case1],value is %d",value);
    }

    t->quit();
    t1->post([&]{
      value = 2;
    });

    usleep(1000*100);
    if(value != 1) {
      TEST_FAIL("[Handler Test Looper Quit case1],value is %d",value);
    }

    t->join();
    break;
  }

  while(1) {
    HandlerThread t = createHandlerThread();
    t->start();

    Handler t1 = createHandler(t->getLooper());
    auto loop = t1->getLooper();
    loop->quit();

    TimeWatcher watch = createTimeWatcher();
    watch->start();
    t->join(100);
    auto l = watch->stop();
    if(l > 105 || l < 95) {
      TEST_FAIL("[Handler Test Looper Quit case2],l is %d",l);
    }
    break;
  }

  TEST_OK("[Handler Test Looper Quit case100]");
}
