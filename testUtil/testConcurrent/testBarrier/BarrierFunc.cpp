#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "TestLog.hpp"
#include "AtomicInteger.hpp"

using namespace obotcha;

int testBarrierFunc() {
  
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
  TEST_OK("[Barrier Test {Func test} case100]");
  return 0;
}
