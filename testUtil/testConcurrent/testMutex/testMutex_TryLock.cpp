#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testMutex_TryLock() {
    TimeWatcher watch = createTimeWatcher();

    while(1) {
      Mutex t = createMutex();
      Thread th = createThread([&t]{
        t->lock();
        usleep(200*1000);
        t->unlock();
      });
      th->start();
      usleep(100*1000);

      watch->start();
      int result = t->tryLock();
      long interval = watch->stop();
      th->join();
      if(result != -EBUSY) {
        TEST_FAIL("[TestMutex tryLock case1],result is %d",result);
        break;
      }

      if(interval > 5 || interval < 0) {
        TEST_FAIL("[TestMutex tryLock case2]");
        break;
      }
      break;
    }

    while(1) {
      Mutex t = createMutex();
      Thread th = createThread([&t]{
        t->tryLock();
        usleep(200*1000);
        t->unlock();
      });
      th->start();
      usleep(100*1000);

      watch->start();
      t->lock();
      long v = watch->stop();
      if(v < 100 || v > 110) {
        TEST_FAIL("[TestMutex tryLock case3],v is %ld",v);
        break;
      }
      break;
    }

    TEST_OK("[TestMutex tryLock case100]");
}
