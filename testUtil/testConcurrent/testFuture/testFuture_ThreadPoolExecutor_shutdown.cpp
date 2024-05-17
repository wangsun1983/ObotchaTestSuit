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

DECLARE_CLASS(FutureThreadPoolCancelTask) IMPLEMENTS(Runnable){
public:
  void run() {
    usleep(1000*100);
    st(ExecutorResult)::Set(100);
  }

  bool onInterrupt() {
    return true;
  }
};

DECLARE_CLASS(FutureThreadPoolNoCancelTask) IMPLEMENTS(Runnable){
public:
  void run() {
    usleep(1000*100);
    st(ExecutorResult)::Set(888);
  }

  bool onInterrupt() {
    return false;
  }
};

void testThreadPoolExecutor_shutdown() {
  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setDefaultThreadNum(32)
              ->newThreadPool();

    Future f = pool->submit(FutureThreadPoolCancelTask::New());

    Thread t = Thread::New([](ThreadPoolExecutor pool) {
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
      TEST_FAIL("[FutureThreadPoolCancelTask case1,interval is %ld",interval);
    }

    if(!isException) {
      TEST_FAIL("[FutureThreadPoolCancelTask case2");
    }

    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setDefaultThreadNum(32)
              ->newThreadPool();

    Future f = pool->submit(FutureThreadPoolNoCancelTask::New());

    Thread t = Thread::New([](ThreadPoolExecutor pool) {
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
      TEST_FAIL("[FutureThreadPoolCancelTask case2,interval is %ld",interval);
    }

    if(isException) {
      TEST_FAIL("[FutureThreadPoolCancelTask case3");
    }

    if(value != 888) {
      TEST_FAIL("[FutureThreadPoolCancelTask case4");
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[FutureThreadPoolCancelTask case100");
}
