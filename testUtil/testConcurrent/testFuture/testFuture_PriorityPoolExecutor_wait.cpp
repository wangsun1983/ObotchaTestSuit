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

void testPriorityPoolExecutor_Wait() {

  TimeWatcher watcher = createTimeWatcher();

  while(1) {
      auto pool = createExecutorBuilder()
                ->setThreadNum(1)
                ->newPriorityThreadPool();
      int value = 100;
      Future f1 = pool->preempt(st(Executor)::High,[&value](){
        usleep(200*1000);
        value = 222;
        st(TaskResult)::set(333);
      });

      watcher->start();
      f1->wait();
      long time = watcher->stop();

      if(time < 200 || time > 205) {
        TEST_FAIL("[Future PriorityThreadPool Wait case1");
        break;
      }
      pool->shutdown();
      pool->awaitTermination();
      break;
  }

  while(1) {
      auto pool = createExecutorBuilder()
              ->setThreadNum(1)
              ->newPriorityThreadPool();
      int value = 100;
      Future f1 = pool->preempt(st(Executor)::High,[&value](){
        usleep(200*1000);
        value = 222;
        st(TaskResult)::set(333);
      });

      watcher->start();
      int ret = f1->wait(100);
      long time = watcher->stop();

      if(time < 100 || time > 105) {
        TEST_FAIL("[Future PriorityThreadPool Wait case2");
        break;
      }

      if(ret != -WaitTimeout) {
        TEST_FAIL("[Future PriorityThreadPool Wait case2_1");
        break;
      }
      pool->shutdown();
      pool->awaitTermination();
      break;
  }

  while(1) {
    auto pool = createExecutorBuilder()->setThreadNum(1)->newPriorityThreadPool();
    int value = 100;
    Future f1 = pool->preempt(st(Executor)::High,[&value](){
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
      TEST_FAIL("[Future PriorityThreadPool Wait case4,time is %d",time);
      //break;
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setThreadNum(3)
                ->newPriorityThreadPool();
    CountDownLatch latch = createCountDownLatch(3);
    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    Future f1 = pool->preempt(st(Executor)::High,[]{
      //
    });

    Future f2 = pool->preempt(st(Executor)::High,[]{
      //
    });

    Future f3 = pool->preempt(st(Executor)::High,[]{
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
    if(result < 95 || result > 105) {
      TEST_FAIL("[Future PriorityThreadPool Wait case5");
      //break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()->setThreadNum(1)->newPriorityThreadPool();
    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    Future f = pool->preempt(st(Executor)::High,[]{
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
      TEST_FAIL("[Future PriorityThreadPool Wait case6");
      //break;
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[Future PriorityThreadPool Wait case100");
}
