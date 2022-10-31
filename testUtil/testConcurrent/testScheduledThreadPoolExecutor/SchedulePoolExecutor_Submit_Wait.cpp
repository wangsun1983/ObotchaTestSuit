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

void testSubmitWait() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    auto f1 = pool->schedule(100,[]{

    });

    watch->start();
    auto f2 = pool->schedule(100,[]{

    });

    long result = watch->stop();

    if(result < 0 || result > 105) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitWait case1]");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(2)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    auto f1 = pool->schedule(200,[]{

    });

    auto f2 = pool->schedule(300,[]{

    });

    watch->start();
    auto f3 = pool->schedule(100,[]{

    });
    long result = watch->stop();
    if(result < 195 || result > 205) {
      TEST_FAIL("[ScheduledThreadPoolExecutor SubmitWait case2]");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[ScheduledThreadPoolExecutor SubmitWait case100]");
}
