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

void testSubmitTask() {
  TimeWatcher watch = TimeWatcher::New();

  while(1) {
    Mutex taskMutex = Mutex::New();
    Condition condition = Condition::New();

    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    auto f1 = pool->schedule(100,[&taskMutex,&condition]{
      AutoLock l(taskMutex);
      condition->notify();
    });

    watch->start();
    AutoLock l(taskMutex);
    condition->wait(taskMutex);
    long result = watch->stop();

    if(result < 100 || result > 105) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTask case1]");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    CountDownLatch latch = CountDownLatch::New(32);
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(64)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    for(int i = 0;i<32;i++) {
      auto f1 = pool->schedule(100,[&latch]{
        latch->countDown();
      });
    }

    watch->start();
    latch->await(300);
    long result = watch->stop();
    if(result < 100 || result > 120) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTask case2],result is %d",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    CountDownLatch latch = CountDownLatch::New(256);
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1024)
              ->setMaxThreadNum(16)
              ->newScheduledThreadPool();
    for(int i = 0;i<256;i++) {
      auto f1 = pool->schedule(100,[&latch]{
        latch->countDown();
      });
    }

    watch->start();
    latch->await(300);
    long result = watch->stop();
    if(result < 100 || result > 150 ) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTask case3],result is %d",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    CountDownLatch latch = CountDownLatch::New(32);
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1024)
              ->setMaxThreadNum(16)
              ->newScheduledThreadPool();
    for(int i = 0;i<31;i++) {
      auto f1 = pool->schedule(100,[&latch]{
        latch->countDown();
      });
    }

    watch->start();
    latch->await(300);
    long result = watch->stop();
    if(result < 300 || result > 305) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTask case4]");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }
  TEST_OK("[ScheduledThreadPoolExecutor SubmitTask case100]");
}
