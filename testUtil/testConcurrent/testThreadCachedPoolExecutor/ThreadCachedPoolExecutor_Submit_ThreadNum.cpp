#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "AutoClose.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void CachedPoolSubmit_ThreadNum() {
  auto pool = createExecutorBuilder()
            ->setQueueSize(1)
            ->setMaxThreadNum(3)
            ->setTimeout(200)
            ->newCachedThreadPool();
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getThreadsNum() != 1 || pool->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test1] threads is %d,tasks is %d ",pool->getThreadsNum(),pool->getTasksNum());
      break;
    }

    Future f2 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getThreadsNum() != 2 || pool->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test2]");
      break;
    }

    Future f3 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getThreadsNum() != 3 || pool->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test3]");
      break;
    }

    Future f4 = pool->submit([]{
      usleep(100*1000);
    });
    if(pool->getThreadsNum() != 3 || pool->getTasksNum() != 1) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test4]");
      break;
    }

    usleep(405*1000);
    if(pool->getThreadsNum() != 0 || pool->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test5] threads is %d,tasks is %d ",pool->getThreadsNum(),pool->getTasksNum());
      break;
    }

    break;
  }

  while(1) {
    for(int i = 0;i < 1024;i++) {
      Future f1 = pool->submit([]{

      });
    }
    usleep(205*1000);
    if(pool->getThreadsNum() != 0 || pool->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test6]threads is %d,tasks is %d ",pool->getThreadsNum(),pool->getTasksNum());
      break;
    }

    break;
  }

  while(1) {
    auto pool2 = createExecutorBuilder()
              ->setQueueSize(12)
              ->setMaxThreadNum(12)
              ->setTimeout(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024;i++) {
      Future f1 = pool2->submit([]{

      });
    }
    usleep(105*1000);
    if(pool2->getThreadsNum() != 0 || pool2->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test7]threads is %d,tasks is %d ",pool2->getThreadsNum(),pool2->getTasksNum());
      break;
    }

    pool2->shutdown();
    pool2->awaitTermination();
    break;
  }

  while(1) {
    auto pool2 = createExecutorBuilder()
              ->setQueueSize(32)
              ->setMaxThreadNum(12)
              ->setTimeout(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024;i++) {
      Future f1 = pool2->submit([]{
        usleep(1);
      });
    }
    usleep(150*1000);
    if(pool2->getThreadsNum() != 0 || pool2->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test8] threads is %d,tasks is %d ",pool2->getThreadsNum(),pool2->getTasksNum());
      break;
    }

    pool2->shutdown();
    pool2->awaitTermination();
    break;
  }

  while(1) {
    auto pool2 = createExecutorBuilder()
              ->setQueueSize(1024*4)
              ->setMaxThreadNum(12)
              ->setTimeout(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024*4;i++) {
      Future f1 = pool2->submit([]{
        usleep(1);
      });
    }

    if(pool2->getThreadsNum() != 12) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test9] threads is %d,tasks is %d ",pool2->getThreadsNum(),pool2->getTasksNum());
      break;
    }

    usleep(150*1000);
    if(pool2->getThreadsNum() != 0 || pool2->getTasksNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test10] threads is %d,tasks is %d ",pool2->getThreadsNum(),pool2->getTasksNum());
      break;
    }

    pool2->shutdown();
    pool2->awaitTermination();
    break;
  }

  pool->shutdown();
  pool->awaitTermination();
  TEST_OK("[TestCachedPoolExecutor ThreadNum test100]");
}
