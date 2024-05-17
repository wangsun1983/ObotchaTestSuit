#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ExecutorBuilder.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Math.hpp"
#include "ExecutorResult.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCachedPoolExecutor_Cancel() {
  auto pool = ExecutorBuilder::New()
              ->setMaxThreadNum(1)
              ->setDefaultThreadNum(1)
              ->newCachedThreadPool();
  while(1) {
      int value = 100;
      Future f1 = pool->submit([&value](){
        usleep(200*1000);
        value = 222;
        st(ExecutorResult)::Set(333);
      });

      Future f2 = pool->submit([](){
        st(ExecutorResult)::Set(100);
      });

      usleep(100*1000);
      f1->cancel();
      f2->cancel();
      usleep(150*1000);
      if(value != 222) {
        TEST_FAIL("[Future CachedPoolExecutor Cancel case2");
        break;
      }

      bool isException = false;
      try {
        int v = f2->getResult<int>();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("[Future CachedPoolExecutor Cancel case3");
        break;
      }
      break;
  }
  while(1) {
    int value = 123;
    Future f1 = pool->submit([&value](){
      value = 222;
      st(ExecutorResult)::Set(333);
    });
    usleep(100*1000);
    f1->cancel();

    if(value != 222) {
      TEST_FAIL("[Future CachedPoolExecutor Cancel case4");
      break;
    }

    if(f1->getResult<int>() != 333) {
      TEST_FAIL("[Future CachedPoolExecutor Cancel case5");
      break;
    }
    break;
  }
  pool->shutdown();
  pool->awaitTermination();

  TEST_OK("[Future CachedPoolExecutor Cancel case100");
}
