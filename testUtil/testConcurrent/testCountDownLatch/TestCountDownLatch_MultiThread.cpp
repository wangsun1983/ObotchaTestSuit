#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "CountDownLatch.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"
#include "AtomicNumber.hpp"

using namespace obotcha;

void testCountDownLatch_MultiThread() {
    TimeWatcher watch = TimeWatcher::New();
    while(1) {
      CountDownLatch l = CountDownLatch::New(16);
      for(int i = 0;i<16;i++) {
        Thread t = Thread::New([&l]{
          l->countDown();
        });
        t->start();
      }

      usleep(100*1000);

      if(l->await() != -1) {
        TEST_FAIL("[TestCountDownLatch MultiThread case1]");
        break;
      }
      break;
    }

    while(1) {
      CountDownLatch l = CountDownLatch::New(16);
      AtomicInteger finishCount = AtomicInteger::New(0);
      for(int i = 0;i<15;i++) {
        Thread t = Thread::New([&l,&finishCount]{
          l->countDown();
          l->await();
          finishCount->incrementAndGet();
        });
        t->start();
      }

      if(finishCount->get() != 0) {
        TEST_FAIL("[TestCountDownLatch MultiThread case2]");
        break;
      }

      l->countDown();
      usleep(100*1000);
      if(finishCount->get() != 15) {
        TEST_FAIL("[TestCountDownLatch MultiThread case3]");
        break;
      }
      break;
    }

    TEST_OK("[TestCountDownLatch MultiThread case100]");
}
