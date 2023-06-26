#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "TestLog.hpp"
#include "AtomicInteger.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

int testBarrierFunc() {

  while(1) {
    AtomicInteger v = createAtomicInteger(0);

    auto func = [&v]{
      for(int i = 0;i<1024;i++) {
        v->incrementAndGet();
      }
    };

    Barrier barrier1 = createBarrier(3);

    Thread t1 = createThread([&func,&barrier1]{
      barrier1->await(func);
    });

    Thread t2 = createThread([&func,&barrier1]{
      barrier1->await(func);
    });

    Thread t3 = createThread([&func,&barrier1]{
      barrier1->await(func);
    });

    t1->start();
    t2->start();
    t3->start();

    t1->join();
    t2->join();
    t3->join();

    if(v->get() != 1024*3) {
       TEST_FAIL("[Barrier Test {Func test} case1]");
    }
    break;
  }

  while(1) {
    AtomicInteger v = createAtomicInteger(0);
    auto func = [&v]{
      usleep(1000 *1000*3);
    };

    Barrier barrier1 = createBarrier(3);
    Thread t1 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 3000 || l > 3005) {
        TEST_FAIL("[Barrier Test {Func test} case2], l is %ld",l);
      }
    });

    Thread t2 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 3000 || l > 3005) {
        TEST_FAIL("[Barrier Test {Func test} case3],l is %ld",l);
      }
    });

    Thread t3 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 3000 || l > 3005) {
        TEST_FAIL("[Barrier Test {Func test} case4],l is %ld",l);
      }
    });

    t1->start();
    t2->start();
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }

  while(1) {
    AtomicInteger v = createAtomicInteger(0);
    auto func = [&v]{
    };

    Barrier barrier1 = createBarrier(4);
    Thread t1 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 995 || l > 1005) {
        TEST_FAIL("[Barrier Test {Func test} case5]");
      }
    });

    Thread t2 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 995 || l > 1005) {
        TEST_FAIL("[Barrier Test {Func test} case6]");
      }
    });

    Thread t3 = createThread([&func,&barrier1]{
      auto watch = createTimeWatcher();
      watch->start();
      barrier1->await(func,1000);
      auto l = watch->stop();
      if(l < 995 || l > 1005) {
        TEST_FAIL("[Barrier Test {Func test} case7]");
      }
    });

    t1->start();
    t2->start();
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }

  TEST_OK("[Barrier Test {Func test} case100]");
  return 0;
}
