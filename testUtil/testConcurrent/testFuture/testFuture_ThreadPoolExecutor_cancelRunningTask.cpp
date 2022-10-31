#include <stdio.h>
#include <unistd.h>
#include <atomic>

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
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(RunningTask) IMPLEMENTS(Runnable) {
public:
    _RunningTask() {
      isStop = 1;
    }

    void run() {
      while(isStop == 1) {
        usleep(1000 * 200);
      }
      st(ExecutorResult)::set(333);
    }

    bool onInterrupt() { 
      isStop = 2;
      return true;
    } 

private:
    std::atomic_int isStop;
};

DECLARE_CLASS(NoStopTask) IMPLEMENTS(Runnable) {
public:
    void run() {
      usleep(1000 * 200);
      st(ExecutorResult)::set(111);
    }

    bool onInterrupt() { 
      return false;
    } 

};

void testThreadPoolExecutor_CancelRunningTask() {

  TimeWatcher watcher = createTimeWatcher();

  while(1) {
      auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newThreadPool();
      
      auto f = pool->submit(createRunningTask());
      usleep(1000*100);

      f->cancel();
      bool isException = false;
      watcher->start();
      try {
        int r = f->getResult<int>();
      } catch(...) {
        isException = true;
      }
      if(watcher->stop() > 5) {
        TEST_FAIL("[Future ThreadPoolExecutor Cancel RunningTask case1");
      }

      if(!isException) {
        TEST_FAIL("[Future ThreadPoolExecutor Cancel RunningTask case2");
      }

      pool->shutdown();
      pool->awaitTermination();
      break;
  }


  while(1) {
      auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newThreadPool();
      
      auto f = pool->submit(createNoStopTask());
      usleep(1000*100);

      f->cancel();
      bool isException = false;
      watcher->start();
      int r = -1;
      try {
        r = f->getResult<int>();
      } catch(...) {
        isException = true;
      }

      long interval = watcher->stop();
      if(interval > 105 || interval < 100) {
        TEST_FAIL("[Future ThreadPoolExecutor Cancel RunningTask case3");
      }

      if(isException) {
        TEST_FAIL("[Future ThreadPoolExecutor Cancel RunningTask case4");
      }

      if(r != 111) {
        TEST_FAIL("[Future ThreadPoolExecutor Cancel RunningTask case5");
      }

      pool->shutdown();
      pool->awaitTermination();
      TEST_OK("[Future ThreadPoolExecutor Cancel RunningTask case6");
      break;
  }



  TEST_OK("[Future ThreadPoolExecutor Cancel RunningTask case100");
}
