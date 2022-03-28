#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "ExecutorBuilder.hpp"
#include "Error.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadPoolSubmit_ShutDown() {
  TimeWatcher watcher = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->newThreadPool();
    Future f1 = pool->submit([]{
      usleep(200*1000);
    });

    Future f2 = pool->submit([]{
    });

    Thread t = createThread([&pool]{
      usleep(100*1000);
      pool->shutdown();
    });
    t->start();
    watcher->start();
    Future f3 = pool->submit([]{
    });
    long result = watcher->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[ThreadPoolExecutor Submit_Shutdown test1] ,result is %ld ",result);
    }

    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->newThreadPool();
    Future f1 = pool->submit([]{
      usleep(200*1000);
    });

    Future f2 = pool->submit([]{
    });

    Thread t = createThread([&pool]{
      usleep(100*1000);
      pool->shutdown();
    });
    t->start();

    watcher->start();
    f2->wait();
    long result = watcher->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[ThreadPoolExecutor Submit_Shutdown test2] ,result is %ld ",result);
    }
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->setQueueSize(1)
                ->setQueueTimeout(300)
                ->newThreadPool();
    Future f1 = pool->submit([]{
      usleep(200*1000);
    });

    Future f2 = pool->submit([]{
    });

    Thread t = createThread([&pool]{
      usleep(100*1000);
      pool->shutdown();
    });
    t->start();

    watcher->start();
    Future f3 = pool->submit([]{
    });
    long result = watcher->stop();
    if(result < 100 || result > 105) {
      TEST_FAIL("[ThreadPoolExecutor Submit_Shutdown test3] ,result is %ld ",result);
    }
    pool->awaitTermination();
    break;
  }

  TEST_OK("[ThreadPoolExecutor Submit_Shutdown test100]");
}
