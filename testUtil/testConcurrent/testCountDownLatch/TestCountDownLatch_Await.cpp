#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "CountDownLatch.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testCountDownLatch_Await() {
    TimeWatcher watcher = createTimeWatcher();
    while(1) {
      CountDownLatch latch = createCountDownLatch(1);
      Thread t = createThread([&latch]{
        usleep(200*1000);
        latch->countDown();
      });
      t->start();
      watcher->start();
      latch->await(100);
      long result = watcher->stop();
      if(result < 100 || result > 105) {
        TEST_FAIL("[TestCountDownLatch await case1]");
        break;
      }

      t->join();
      watcher->start();
      latch->await(100);
      result = watcher->stop();
      if(result > 5) {
        TEST_FAIL("[TestCountDownLatch await case2]");
        break;
      }
      break;
    }



    TEST_OK("[TestCountDownLatch CountDown case100]");
}
