#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "Integer.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testConditionWaitWithOwner() {
    TimeWatcher watch = TimeWatcher::New();
    while(1) {
      Mutex mMutex = Mutex::New();
      Condition c = Condition::New();
      long result = 0;
      Thread t = Thread::New([&mMutex,&c,&result,&watch]{
        watch->start();
        AutoLock l(mMutex);
        int ret = c->wait(mMutex,100);
        result = watch->stop();
      });
      t->start();

      usleep(1000*200);
      if(result < 100 || result > 105) {
        TEST_FAIL("Condition Wait Case1 test1");
        break;
      }

      TEST_OK("Condition Wait Case1 test2");
      break;
    }

    while(1) {
      Mutex mMutex = Mutex::New();
      Condition c = Condition::New();
      AutoLock l(mMutex);
      watch->start();
      int ret = c->wait(mMutex,300);
      if(ret != -ETIMEDOUT) {
        TEST_FAIL("Condition Wait Case1 test3,ret is %d",ret);
        break;
      }
      long interval = watch->stop();
      if(interval > 305 || interval < 300) {
        TEST_FAIL("Condition Wait Case1 test4");
        break;
      }
      TEST_OK("Condition Wait Case1 test5");
      break;
    }

    while(1) {
      Mutex mMutex = Mutex::New();
      Condition c = Condition::New();
      long result = 0;
      Thread t = Thread::New([&c]{
        usleep(100*1000);
        c->notify();
      });
      t->start();

      AutoLock l(mMutex);
      watch->start();
      c->wait(mMutex);
      result = watch->stop();
      if(result < 100 || result > 105) {
        TEST_FAIL("Condition Wait Case1 test6");
        break;
      }

      TEST_OK("Condition Wait Case1 test7");
      break;
    }
}
