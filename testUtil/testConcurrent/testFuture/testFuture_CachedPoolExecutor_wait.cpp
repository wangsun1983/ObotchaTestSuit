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
#include "TimeWatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCachedPoolExecutor_Wait() {

  TimeWatcher watcher = createTimeWatcher();

  while(1) {
      auto pool = createExecutorBuilder()
                ->setMaxThreadNum(1)
                ->setThreadNum(1)
                ->newCachedThreadPool();
      int value = 100;
      Future f1 = pool->submit([&value](){
        usleep(200*1000);
        value = 222;
        st(TaskResult)::set(333);
      });

      watcher->start();
      f1->wait();
      long time = watcher->stop();

      if(time < 200 || time > 205) {
        TEST_FAIL("[Future CahcedPoolExecutor Wait case1");
      }

      pool->shutdown();
      pool->awaitTermination();
      break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setMaxThreadNum(1)
                ->setThreadNum(1)
                ->newCachedThreadPool();
      int value = 100;
      Future f1 = pool->submit([&value](){
        usleep(200*1000);
        value = 222;
        st(TaskResult)::set(333);
      });

      watcher->start();
      int ret = f1->wait(100);
      long time = watcher->stop();

      if(time < 100 || time > 105) {
        TEST_FAIL("[Future CahcedPoolExecutor Wait case2");
      }

      if(ret != -ETIMEDOUT) {
        TEST_FAIL("[Future CahcedPoolExecutor Wait case2_1");
      }
      pool->shutdown();
      pool->awaitTermination();
      break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setMaxThreadNum(1)
                ->setThreadNum(1)
                ->newCachedThreadPool();
    int value = 100;
    Future f1 = pool->submit([&value](){
      usleep(200*1000);
      value = 222;
      st(TaskResult)::set(333);
    });
    usleep(100);
    f1->cancel();
    watcher->start();
    int ret = f1->wait(100);
    long time = watcher->stop();
    if(time < 95 || time > 105) {
      TEST_FAIL("[Future CahcedPoolExecutor Wait case4");
      //break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setMaxThreadNum(3)
                ->setThreadNum(1)
                ->newCachedThreadPool();
    CountDownLatch latch = createCountDownLatch(3);
    pool->submit([]{
      usleep(100*1000);
    });

    pool->submit([]{
      usleep(100*1000);
    });

    pool->submit([]{
      usleep(100*1000);
    });

    Future f1 = pool->submit([]{
      //
    });

    Future f2 = pool->submit([]{
      //
    });

    Future f3 = pool->submit([]{
      //
    });

    Thread t1 = createThread([&f1,&latch]{
      f1->wait();
      latch->countDown();
    });
    t1->start();

    Thread t2 = createThread([&f2,&latch]{
      f2->wait();
      latch->countDown();
    });
    t2->start();

    Thread t3 = createThread([&f3,&latch]{
      f3->wait();
      latch->countDown();
    });
    t3->start();

    watcher->start();
    latch->await();
    long result = watcher->stop();
    if(result < 90 || result > 105) {
      TEST_FAIL("[Future CahcedPoolExecutor Wait case5,result is %ld",result);
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setMaxThreadNum(1)
                ->setThreadNum(1)
                ->newCachedThreadPool();
    pool->submit([]{
      usleep(100*1000);
    });

    Future f = pool->submit([]{
      //TODO
    });

    Thread t = createThread([&pool]{
      usleep(10*1000);
      pool->shutdown();
    });
    t->start();

    watcher->start();
    f->wait();
    long result = watcher->stop();
    if(result < 10 || result > 15) {
      TEST_FAIL("[Future CahcedPoolExecutor Wait case6");
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[Future CahcedPoolExecutor Wait case100");
}
