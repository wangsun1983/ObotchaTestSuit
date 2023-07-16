#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void CachedPoolSubmit_Timeout() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(1)
              ->setMaxSubmitTaskWaitTime(100)
              ->setMaxThreadNum(1)
              ->setMaxNoWorkingTime(200)
              ->newCachedThreadPool();

    Future f1 = pool->submit([]{
      usleep(200*1000);
    });

    Future f2 = pool->submit([]{
    });

    watch->start();
    Future f3 = pool->submit([]{

    });
    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestCachedPoolExecutor Submit Timeout test1],result is %ld ",result);
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(1)
              ->setMaxSubmitTaskWaitTime(200)
              ->setMaxThreadNum(1)
              ->setMaxNoWorkingTime(200)
              ->newCachedThreadPool();

    Future f1 = pool->submit([]{
      usleep(300*1000);
    });

    Future f2 = pool->submit([]{
    });

    Thread t = createThread([&pool]{
        usleep(100*1000);
        pool->shutdown();
    });
    t->start();

    watch->start();
    Future f3 = pool->submit([]{
    });
    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestCachedPoolExecutor Submit Timeout test2] result is %ld",result);
      break;
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[TestCachedPoolExecutor Submit Timeout test100]");
}
