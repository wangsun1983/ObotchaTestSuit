#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAwaitTermination() {
  TimeWatcher watch = TimeWatcher::New();
  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1)
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[]{
      usleep(100*1000);
    });

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[]{
      usleep(100*1000);
    });

    pool->shutdown();
    watch->start();
    pool->awaitTermination();
    long result = watch->stop();

    if(result < 100 || result > 105) {
      TEST_FAIL("[TestPriorityPoolExecutor Await Termination Test case1]");
      break;
    }
    break;
  }

  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1)
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[]{
      usleep(200*1000);
    });
    usleep(10);

    pool->shutdown();
    watch->start();
    pool->awaitTermination(100);
    long result = watch->stop();

    if(result < 100 || result > 105) {
      TEST_FAIL("[TestPriorityPoolExecutor Await Termination Test case2]");
      break;
    }
    break;
  }

  TEST_OK("[TestPriorityPoolExecutor Await Termination Test case100]");

}
