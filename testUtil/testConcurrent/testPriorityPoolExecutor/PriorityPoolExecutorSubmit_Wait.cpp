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

void testSubmitWait() {
  TimeWatcher watch = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Medium,[]{
      usleep(100*1000);
    });

    pool->preempt(st(Executor)::Medium,[]{
      usleep(100*1000);
    });

    watch->start();
    pool->preempt(st(Executor)::Medium,[]{

    });
    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitWait Test case1]");
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Medium,[]{
      usleep(100*1000);
    });

    pool->preempt(st(Executor)::Medium,[]{

    });

    watch->start();
    pool->preempt(st(Executor)::High,[]{

    });
    long result = watch->stop();
    if(result < 0 || result > 5) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitWait Test case2]");
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setQueueTimeout(100)
              ->setThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Medium,[]{
      usleep(200*1000);
    });

    pool->preempt(st(Executor)::Medium,[]{
    });

    watch->start();
    pool->preempt(st(Executor)::Medium,[]{
    });

    long result = watch->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitWait Test case3]");
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }
  TEST_OK("[TestPriorityPoolExecutor SubmitWait Test case100]");

}
