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

void CachedPoolSubmit_Wait() {
  auto pool = ExecutorBuilder::New()
            ->setMaxPendingTaskNum(1)
            ->setMaxThreadNum(1)
            ->setMaxNoWorkingTime(200)
            ->newCachedThreadPool();
  TimeWatcher watch = TimeWatcher::New();

  while(1) {
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });

    Future f2 = pool->submit([]{
    });

    watch->start();
    Future f3 = pool->submit([]{
    });
    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestCachedPoolExecutor SubmitWait test1]");
      break;
    }

    usleep(250*1000);
    if(pool->getExecutingThreadNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor SubmitWait test2]");
      break;
    }
    break;
  }

  while(1) {
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });

    Future f2 = pool->submit([]{
      usleep(100*1000);
    });

    watch->start();
    Future f3 = pool->submit([]{
    });
    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestCachedPoolExecutor SubmitWait test3]result is %ld ",result);
      break;
    }

    watch->start();
    f3->wait();
    result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestCachedPoolExecutor SubmitWait test4]result is %ld ",result);
      break;
    }

    usleep(250*1000);
    if(pool->getExecutingThreadNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor SubmitWait test5]");
      break;
    }
    break;
  }

  pool->shutdown();
  pool->awaitTermination();
  TEST_OK("[TestCachedPoolExecutor SubmitWait test100]");
}
