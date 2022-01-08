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
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->newThreadPool();
    pool->execute([]{
      usleep(200*1000);
    });

    pool->execute([]{
    });

    watcher->start();
    pool->executeWithInTime(100,[]{

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
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->newThreadPool();
    watcher->start();
    pool->executeWithInTime(100,[]{
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
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->newThreadPool();
    watcher->start();
    pool->execute([]{
      usleep(200*1000);
    });

    pool->execute([]{
    });

    watcher->start();
    pool->executeWithInTime(300,[]{

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
