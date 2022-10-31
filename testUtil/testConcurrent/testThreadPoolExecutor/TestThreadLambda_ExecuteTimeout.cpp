#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadLambdaExecuteTimeout() {
  TimeWatcher watcher = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->setMaxPendingTaskNum(1)
                ->setMaxSubmitTaskWaitTime(100)
                ->newThreadPool();

    pool->submit([]{
      usleep(200*1000);
    });

    pool->submit([]{
    });

    watcher->start();

    pool->submit([]{

    });
    long result = watcher->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[ThreadPoolExecutor execute_Timeout test1],result is %ld ",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->setMaxPendingTaskNum(1)
                ->setMaxSubmitTaskWaitTime(100)
                ->newThreadPool();
    watcher->start();
    pool->submit([]{
      usleep(200*1000);
    });
    long result = watcher->stop();
    if(result < 0 || result > 5) {
      TEST_FAIL("[ThreadPoolExecutor execute_Timeout test2],result is %ld ",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->setMaxPendingTaskNum(1)
                ->setMaxSubmitTaskWaitTime(300)
                ->newThreadPool();
    watcher->start();
    pool->submit([]{
      usleep(200*1000);
    });

    pool->submit([]{
    });

    watcher->start();
    pool->submit([]{

    });

    long result = watcher->stop();
    if(result < 200 || result > 205) {
      TEST_FAIL("[ThreadPoolExecutor execute_Timeout test3],result is %ld ",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[ThreadPoolExecutor execute_Timeout test100]");
}
