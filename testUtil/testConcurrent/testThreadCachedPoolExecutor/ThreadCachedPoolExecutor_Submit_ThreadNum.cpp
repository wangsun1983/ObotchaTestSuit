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
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void CachedPoolSubmit_ThreadNum() {
  auto pool = ExecutorBuilder::New()
            ->setMaxPendingTaskNum(1)
            ->setMaxThreadNum(3)
            ->setMaxNoWorkingTime(200)
            ->newCachedThreadPool();
  TimeWatcher watch = TimeWatcher::New();


  while(1) {
    Future f1 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getExecutingThreadNum() != 1 || pool->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test1] threads is %d,tasks is %d ",pool->getExecutingThreadNum(),pool->getPendingTaskNum());
      break;
    }

    Future f2 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getExecutingThreadNum() != 2 || pool->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test2]");
      break;
    }

    Future f3 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000);
    if(pool->getExecutingThreadNum() != 3 || pool->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test3]");
      break;
    }

    Future f4 = pool->submit([]{
      usleep(100*1000);
    });
    if(pool->getExecutingThreadNum() != 3 || pool->getPendingTaskNum() != 1) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test4]");
      break;
    }

    usleep(405*1000);
    if(pool->getExecutingThreadNum() != 0 || pool->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test5] threads is %d,tasks is %d ",pool->getExecutingThreadNum(),pool->getPendingTaskNum());
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
    if(pool->getExecutingThreadNum() != 0 || pool->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test6]threads is %d,tasks is %d ",pool->getExecutingThreadNum(),pool->getPendingTaskNum());
      break;
    }

    break;
  }

  while(1) {
    auto pool2 = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(12)
              ->setMaxThreadNum(12)
              ->setMaxNoWorkingTime(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024;i++) {
      Future f1 = pool2->submit([]{

      });
    }
    usleep(105*1000);
    if(pool2->getExecutingThreadNum() != 0 || pool2->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test7]threads is %d,tasks is %d ",pool2->getExecutingThreadNum(),pool2->getPendingTaskNum());
      break;
    }

    pool2->shutdown();
    pool2->awaitTermination();
    break;
  }

  while(1) {
    auto pool2 = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(32)
              ->setMaxThreadNum(12)
              ->setMaxNoWorkingTime(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024;i++) {
      Future f1 = pool2->submit([]{
        usleep(1);
      });
    }
    usleep(150*1000);
    if(pool2->getExecutingThreadNum() != 0 || pool2->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test8] threads is %d,tasks is %d ",pool2->getExecutingThreadNum(),pool2->getPendingTaskNum());
      break;
    }

    pool2->shutdown();
    pool2->awaitTermination();
    break;
  }


  while(1) {
    auto pool2 = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(1024*4)
              ->setMaxThreadNum(12)
              ->setMaxNoWorkingTime(100)
              ->newCachedThreadPool();
    for(int i = 0;i < 1024*4;i++) {
      Future f1 = pool2->submit([]{
        usleep(1);
      });
    }

    if(pool2->getExecutingThreadNum() != 12) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test9] threads is %d,tasks is %d ",pool2->getExecutingThreadNum(),pool2->getPendingTaskNum());
      break;
    }

    usleep(250*1000);
    if(pool2->getExecutingThreadNum() != 0 || pool2->getPendingTaskNum() != 0) {
      TEST_FAIL("[TestCachedPoolExecutor ThreadNum test10] threads is %d,tasks is %d ",pool2->getExecutingThreadNum(),pool2->getPendingTaskNum());
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
