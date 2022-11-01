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

void testCountDownLatch_CountDown() {
    TimeWatcher watcher = createTimeWatcher();
    while(1) {
      CountDownLatch latch = createCountDownLatch(1);
      Thread t = createThread([&latch]{
        usleep(100*1000);
        latch->countDown();
      });
      t->start();
      watcher->start();
      latch->await();
      long result = watcher->stop();
      if(result < 100 || result > 105) {
        TEST_FAIL("[TestCountDownLatch CountDown case1]");
        break;
      }
      break;
    }

    while(1) {
      CountDownLatch latch = createCountDownLatch(2);
      Thread t = createThread([&latch]{
        usleep(100*1000);
        latch->countDown();
      });
      t->start();
      watcher->start();
      latch->await(200);
      long result = watcher->stop();
      if(result < 200 || result > 205) {
        TEST_FAIL("[TestCountDownLatch CountDown case2]");
        break;
      }
      break;
    }

    while(1) {
      CountDownLatch latch = createCountDownLatch(2);
      if(latch->countDown() != 0) {
        TEST_FAIL("[TestCountDownLatch CountDown case3]");
        break;
      }

      if(latch->countDown() != 0) {
        TEST_FAIL("[TestCountDownLatch CountDown case4]");
        break;
      }

      if(latch->countDown() != -1) {
        TEST_FAIL("[TestCountDownLatch CountDown case5]");
        break;
      }
      break;
    }

    TEST_OK("[TestCountDownLatch CountDown case100]");
}
