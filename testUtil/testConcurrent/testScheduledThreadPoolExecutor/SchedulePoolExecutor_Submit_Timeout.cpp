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
#include "TestLog.hpp"

using namespace obotcha;

void testSubmitTimeout() {
  TimeWatcher watch = TimeWatcher::New();

  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1)
              ->setMaxThreadNum(3)
              ->setMaxSubmitTaskWaitTime(50)
              ->newScheduledThreadPool();
    auto f1 = pool->schedule(200,[]{

    });

    watch->start();
    auto f2 = pool->schedule(100,[]{

    });

    long result = watch->stop();

    if(result < 0 || result > 55) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTimeout case1],result is %d",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }


  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(2)
              ->setMaxThreadNum(3)
              ->setMaxNoWorkingTime(50)
              ->newScheduledThreadPool();

    auto f1 = pool->schedule(200,[]{

    });

    watch->start();
    auto f2 = pool->schedule(100,[]{

    });

    long result = watch->stop();
    if(result < 0 || result > 5) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitTimeout case2]");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[ScheduledThreadPoolExecutor SubmitTimeout case100]");
}
