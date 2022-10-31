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

void testScheduledPoolExecutor_Cancel() {
  auto pool = createExecutorBuilder()
            ->setMaxPendingTaskNum(32)
            ->newScheduledThreadPool();

  while(1) {
      int value = 100;
      Future f1 = pool->schedule(200,[&value](){
        value = 222;
        st(ExecutorResult)::set(333);
      });

      Future f2 = pool->schedule(0,[](){
        st(ExecutorResult)::set(100);
      });

      usleep(100*1000);
      f1->cancel();
      f2->cancel();
      usleep(150*1000);
      if(value == 222) {
        TEST_FAIL("[Future ScheduledPoolExecutor Cancel case2");
        break;
      }

      bool isException = false;
      int v = f2->getResult<int>();

      if(v != 100) {
        TEST_FAIL("[Future ScheduledPoolExecutor Cancel case3");
        break;
      }
      break;
  }

  while(1) {
    int value = 123;
    Future f1 = pool->schedule(0,[&value](){
      usleep(200*100);
      value = 222;
      st(ExecutorResult)::set(333);
    });
    usleep(10*1000);
    f1->cancel();
    usleep(200*1000);
    if(value != 222) {
      TEST_FAIL("[Future ScheduledPoolExecutor Cancel case4");
      break;
    }

    if(f1->getResult<int>() != 333) {
      TEST_FAIL("[Future ScheduledPoolExecutor Cancel case5");
      break;
    }
    break;
  }

  pool->shutdown();
  pool->awaitTermination();

  TEST_OK("[Future ScheduledPoolExecutor Cancel case100");
}
