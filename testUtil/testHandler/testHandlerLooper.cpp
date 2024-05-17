#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "HandlerThread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testHandlerLooper() {
  //case 1
  while(1) {
    HandlerThread t = HandlerThread::New();
    t->start();

    Handler t1 = Handler::New(t->getLooper());
    Handler t2 = Handler::New(t->getLooper());
    TimeWatcher watcher = TimeWatcher::New();
    t1->post([]{
      sleep(1);
    });

    long result = 0;
    watcher->start();
    t2->post([&]{
      result = watcher->stop();
    });

    sleep(2);
    if(result < 995 ||result > 1005) {
      TEST_FAIL("[Handler Test Looper case1],result is %d",result);
    }
    break;
  }

  TEST_OK("[Handler Test Looper case100]");
}
