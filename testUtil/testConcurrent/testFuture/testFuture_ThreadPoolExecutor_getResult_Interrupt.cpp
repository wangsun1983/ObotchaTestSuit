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
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(InterruptTestData) {
public:
  _InterruptTestData(int p) {
    v = p;
  }

  int v;
};

void testThreadPoolExecutor_GetResult_Interrupt() {
  TimeWatcher watcher = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newThreadPool();

    Future f1 = pool->submit([]{
      usleep(100*1000);
      st(ExecutorResult)::set(100);
    });

    usleep(10*1000);
    pool->shutdown();

    watcher->start();
    int v = f1->getResult<int>();
    long result = watcher->stop();

    if(result < 85 || result > 95) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case1");
      break;
    }

    if(v != 100) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case2");
      break;
    }

    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newThreadPool();
    pool->submit([] {
      usleep(100*1000);
    });

    Future f1 = pool->submit([]{
      st(ExecutorResult)::set(createInterruptTestData(123));
    });

    Thread t = createThread([&pool]{
      usleep(10*1000);
      pool->shutdown();
    });
    t->start();

    watcher->start();
    InterruptTestData v = nullptr;
    bool isException = false;
    try {
      v = f1->getResult<InterruptTestData>();
    } catch(...) {
      isException = true;
    }

    long result = watcher->stop();
    if(result < 5 || result > 15) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case3");
      break;
    }

    if(v != nullptr) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case4");
      break;
    }

    if(!isException) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case4_1");
      break;
    }

    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newThreadPool();
    pool->submit([] {
      usleep(100*1000);
    });

    Future f1 = pool->submit([]{
      st(ExecutorResult)::set(123);
    });

    Thread t = createThread([&pool]{
      usleep(10*1000);
      pool->shutdown();
    });
    t->start();

    watcher->start();
    bool isException = false;
    try {
      auto v = f1->getResult<int>();
    } catch(...) {
      isException = true;
    }

    long result = watcher->stop();
    if(result < 5 || result > 15) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case5");
      break;
    }

    if(!isException) {
      TEST_FAIL("[Future ThreadPoolExecutor GetResult Interrupt case6");
      break;
    }

    pool->awaitTermination();
    break;
  }

  TEST_OK("[Future ThreadPoolExecutor GetResult Interrupt case100");
}
