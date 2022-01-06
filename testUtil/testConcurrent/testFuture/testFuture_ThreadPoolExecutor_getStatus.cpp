#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ExecutorBuilder.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Math.hpp"
#include "TaskResult.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadPoolExecutor_getStatus() {
  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->newThreadPool();
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });

    Future f2 = pool->submit([]{

    });
    usleep(10*1000);

    pool->shutdown();
    if(f2->getStatus() != st(Future)::Cancel) {
      TEST_FAIL("[Future ThreadPoolExecutor getStatus case1");
      break;
    }

    pool->awaitTermination();
    if(f1->getStatus() != st(Future)::Complete) {
      TEST_FAIL("[Future ThreadPoolExecutor getStatus case2");
      break;
    }

    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->newThreadPool();
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });

    Future f2 = pool->submit([]{
      usleep(100*1000);
    });

    if(f2->getStatus() != st(Future)::Waiting) {
      TEST_FAIL("[Future ThreadPoolExecutor getStatus case3");
      break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[Future ThreadPoolExecutor getStatus case100");
}
