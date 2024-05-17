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
    HandlerThread t = HandlerThread::New();
    t->start();

    Handler t1 = Handler::New(t->getLooper());
    int value = 100;
    TimeWatcher watcher = TimeWatcher::New();
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
    HandlerThread t = HandlerThread::New();
    t->start();
    
    usleep(100*1000);
    Handler t1 = Handler::New(t->getLooper());
    auto loop = t1->getLooper();
    loop->quit();

    TimeWatcher watch = TimeWatcher::New();
    watch->start();
    t->join(100);
    auto l = watch->stop();
    if(l > 5) {
      TEST_FAIL("[Handler Test Looper Quit case2],l is %d",l);
    }
    break;
  }

  TEST_OK("[Handler Test Looper Quit case100]");
}
