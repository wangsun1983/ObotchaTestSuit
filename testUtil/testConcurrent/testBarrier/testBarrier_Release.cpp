#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBarrierRelease() {
  while(1) {
    Barrier barrier1 = createBarrier(3);
    Thread t1 = createThread([&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await();
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case1],l is %ld",l);
      }
    });

    Thread t2 = createThread([&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await();
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case2],l is %ld",l);
      }
    });

    t1->start();
    t2->start();

    usleep(1000*100);
    Thread t3 = createThread([&barrier1]{
      barrier1->release();
    });
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }

  while(1) {
    Barrier barrier1 = createBarrier(3);
    Thread t1 = createThread([&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(1000);
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case3],l is %ld",l);
      }
    });

    Thread t2 = createThread([&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(1000);
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case4],l is %ld",l);
      }
    });

    t1->start();
    t2->start();

    usleep(1000*100);
    Thread t3 = createThread([&barrier1]{
      barrier1->release();
    });
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }

  TEST_OK("[Barrier Test {Release test} case100]");
}
