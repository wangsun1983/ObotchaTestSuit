#include <stdio.h>
#include <unistd.h>
#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSubmitMultiThread() {
  TimeWatcher watch = TimeWatcher::New();
  while(1) {
    CountDownLatch latch = CountDownLatch::New(32*1024*3);

    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(32)
              ->setDefaultThreadNum(4)
              ->newPriorityThreadPool();
    Mutex mutex1 = Mutex::New();
    int count1 = 0;

    Mutex mutex2 = Mutex::New();
    int count2 = 0;

    Mutex mutex3 = Mutex::New();
    int count3 = 0;

    Thread t1 = Thread::New([&count1,&pool,&latch,&mutex1]{
      for(int i = 0;i<1024*32;i++) {
        pool->preempt(st(Concurrent)::TaskPriority::Low,[&count1,&latch,&mutex1]{
          {
            AutoLock l(mutex1);
            count1 = count1 + 1;
          }
          latch->countDown();
        });
      }
    });
    t1->start();

    Thread t2 = Thread::New([&count2,&pool,&latch,&mutex2]{
      for(int i = 0;i<1024*32;i++) {
        pool->preempt(st(Concurrent)::TaskPriority::Medium,[&count2,&latch,&mutex2]{
          {
            AutoLock l(mutex2);
            count2 = count2 + 2;
          }
          latch->countDown();
        });
      }
    });
    t2->start();

    Thread t3 = Thread::New([&count3,&pool,&latch,&mutex3]{
      for(int i = 0;i<1024*32;i++) {
        pool->preempt(st(Concurrent)::TaskPriority::High,[&count3,&latch,&mutex3]{
          {
            AutoLock l(mutex3);
            count3 = count3 + 3;
          }
          latch->countDown();
        });
      }
    });
    t3->start();

    latch->await();
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for(int i = 0;i < 1024*32;i++) {
      sum1 = sum1 + 1;
    }

    for(int i = 0;i < 1024*32;i++) {
      sum2 = sum2 + 2;
    }

    for(int i = 0;i < 1024*32;i++) {
      sum3 = sum3 + 3;
    }

    if(sum1 != count1) {
      TEST_FAIL("[TestPriorityPoolExecutor MultiThread Test case1]");
      //break;
    }

    if(sum2 != count2) {
      TEST_FAIL("[TestPriorityPoolExecutor MultiThread Test case2]");
      //break;
    }

    if(sum3 != count3) {
      TEST_FAIL("[TestPriorityPoolExecutor MultiThread Test case3]");
      //break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[TestPriorityPoolExecutor SubmitPriority Test case100]");
}
