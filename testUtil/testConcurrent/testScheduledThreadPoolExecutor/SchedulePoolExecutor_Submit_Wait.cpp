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

using namespace obotcha;

void testSubmitWait() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(1)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    auto f1 = pool->submit(100,[]{

    });

    watch->start();
    auto f2 = pool->submit(100,[]{

    });

    long result = watch->stop();

    if(result < 0 || result > 105) {
      printf("---[ScheduledThreadPoolExecutor SubmitWait case1] [FAILED]--- \n");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(2)
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
    auto f1 = pool->submit(200,[]{

    });

    auto f2 = pool->submit(300,[]{

    });

    watch->start();
    auto f3 = pool->submit(100,[]{

    });
    long result = watch->stop();
    if(result < 195 || result > 205) {
      printf("---[ScheduledThreadPoolExecutor SubmitWait case2] [FAILED]---,result is %ld \n",result);
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  printf("---[ScheduledThreadPoolExecutor SubmitWait case100] [OK]--- \n");
}
