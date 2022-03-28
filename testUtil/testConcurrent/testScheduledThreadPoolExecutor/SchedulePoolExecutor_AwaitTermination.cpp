#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Long.hpp"
#include "TimeWatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAwaitTermination() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    pool->schedule(100,[]{

    });

    pool->shutdown();
    watch->start();
    pool->awaitTermination();
    long result = watch->stop();
    if(result < 0 || result > 5) {
      TEST_FAIL("[ScheduledThreadPoolExecutor awaitTermination case1]");
    }
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    pool->schedule(0,[]{
      usleep(200*1000);
    });
    usleep(100*1000);
    pool->shutdown();
    watch->start();
    pool->awaitTermination();
    long result = watch->stop();
    if(result < 100 || result > 205) {
      TEST_FAIL("[ScheduledThreadPoolExecutor awaitTermination case2]");
    }
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    pool->schedule(0,[]{
      usleep(200*1000);
    });
    usleep(100*1000);
    pool->shutdown();
    watch->start();
    pool->awaitTermination(50);
    long result = watch->stop();
    if(result < 50 || result > 55) {
      TEST_FAIL("[ScheduledThreadPoolExecutor awaitTermination case3]");
    }
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    pool->schedule(0,[]{
    });
    usleep(100*1000);
    pool->shutdown();
    watch->start();
    pool->awaitTermination(50);
    long result = watch->stop();
    if(result < 0 || result > 5) {
      TEST_FAIL("[ScheduledThreadPoolExecutor awaitTermination case4]");
    }
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    pool->schedule(0,[]{
      usleep(200*1000);
    });
    usleep(100*1000);
    pool->shutdown();
    watch->start();
    pool->awaitTermination(300);

    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[ScheduledThreadPoolExecutor awaitTermination case5]");
    }
    break;
  }
  TEST_OK("[ScheduledThreadPoolExecutor awaitTermination case100]");
}
