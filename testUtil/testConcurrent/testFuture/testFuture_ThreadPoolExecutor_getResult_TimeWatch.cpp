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

void testThreadPoolExecutor_GetResult_TimeWatch() {
  auto pool = ExecutorBuilder::New()
              ->setDefaultThreadNum(1)
              ->newThreadPool();

  TimeWatcher watcher = TimeWatcher::New();
  while(1) {
      Future f1 = pool->submit([]{
          usleep(200*1000);
          st(ExecutorResult)::Set(111);
      });
      watcher->start();
      int ret = f1->getResult<int>();
      long interval = watcher->stop();
      if(interval<200 || interval > 205) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult TimeWatch case1");
        break;
      }

      if(ret != 111) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult TimeWatch case2");
        break;
      }
      break;
  }

  while(1) {
      Future f1 = pool->submit([]{
          usleep(200*1000);
      });
      watcher->start();
      bool isException = false;
      try {
        int ret = f1->getResult<int>();
      } catch(...) {

      }
      long interval = watcher->stop();
      if(interval<200 || interval > 205) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult TimeWatch case3");
        break;
      }

      break;
  }

  while(1) {
      Future f1 = pool->submit([]{
          usleep(200*1000);
      });
      watcher->start();
      bool isException = false;
      try {
        int ret = f1->getResult<int>(100);
      } catch(...) {
        isException = true;
      }

      long interval = watcher->stop();
      if(!isException || interval<100 || interval > 105) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult TimeWatch case4");
        break;
      }

      break;
  }

  while(1) {
      Future f1 = pool->submit([]{
          usleep(200*1000);
          st(ExecutorResult)::Set(123);
      });
      watcher->start();
      bool isException = false;
      int ret = 0;

      try {
        ret = f1->getResult<int>(100);
      } catch(...) {
        isException = true;
      }

      long interval = watcher->stop();
      if(!isException || interval<100 || interval > 105 || ret != 0) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult TimeWatch case5");
        break;
      }

      break;
  }

  pool->shutdown();
  pool->awaitTermination();

  TEST_OK("[Future ThreadPoolExecutor GetResult TimeWatch case100");
}
