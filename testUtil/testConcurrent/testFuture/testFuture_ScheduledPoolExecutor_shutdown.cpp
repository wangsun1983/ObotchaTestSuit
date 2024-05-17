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
#include "ExecutorResult.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

DECLARE_CLASS(FutureScheduledPoolCancelTask) IMPLEMENTS(Runnable){
public:
  void run() {
    usleep(1000*100);
    st(ExecutorResult)::Set(100);
  }

  bool onInterrupt() {
    return true;
  }
};

DECLARE_CLASS(FutureScheduledNoCancelTask) IMPLEMENTS(Runnable){
public:
  void run() {
    usleep(1000*100);
    st(ExecutorResult)::Set(888);
  }

  bool onInterrupt() {
    return false;
  }
};

void testScheduledPoolExecutor_shutdown() {
  while(1) {
    auto pool = ExecutorBuilder::New()
              ->newScheduledThreadPool();

    Future f = pool->submit(FutureScheduledPoolCancelTask::New());

    Thread t = Thread::New([](ThreadScheduledPoolExecutor pool) {
        usleep(1000*50);
        pool->shutdown();
    },pool);
    t->start();

    TimeWatcher watch = TimeWatcher::New();
    watch->start();
    bool isException = false;
    try {
      int value = f->getResult<int>();
    } catch(...) {
      isException = true;
    }

    long interval = watch->stop();
    if(interval > 55 || interval < 50) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case1,interval is %ld",interval);
    }

    if(!isException) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case2");
    }

    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = ExecutorBuilder::New()
              ->newScheduledThreadPool();

    Future f = pool->submit(FutureScheduledNoCancelTask::New());

    Thread t = Thread::New([](ThreadScheduledPoolExecutor pool) {
        usleep(1000*50);
        pool->shutdown();
    },pool);
    t->start();

    TimeWatcher watch = TimeWatcher::New();
    watch->start();
    bool isException = false;
    int value = 0;

    try {
      value = f->getResult<int>();
    } catch(...) {
      isException = true;
    }

    long interval = watch->stop();
    if(interval > 105 || interval < 100) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case2,interval is %ld",interval);
    }

    if(isException) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case3");
    }

    if(value != 888) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case4");
    }

    pool->awaitTermination();
    break;
  }

  //test delay task
  while(1) {
    auto pool = ExecutorBuilder::New()
              ->newScheduledThreadPool();

    Future f = pool->schedule(300,FutureScheduledPoolCancelTask::New());

    Thread t = Thread::New([](ThreadScheduledPoolExecutor pool) {
        usleep(1000*50);
        pool->shutdown();
    },pool);
    t->start();

    TimeWatcher watch = TimeWatcher::New();
    watch->start();
    bool isException = false;
    try {
      int value = f->getResult<int>();
    } catch(...) {
      isException = true;
    }

    long interval = watch->stop();
    if(interval > 55 || interval < 50) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case5,interval is %ld",interval);
    }

    if(!isException) {
      TEST_FAIL("[FutureScheduledPoolCancelTask case6");
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[FutureScheduledPoolCancelTask case100");
}
