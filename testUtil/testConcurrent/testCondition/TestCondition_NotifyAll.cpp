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
#include "AtomicInteger.hpp"

using namespace obotcha;

void testConditionNotifyAll() {
    TimeWatcher watch = createTimeWatcher();
    while(1) {
      AtomicInteger v = createAtomicInteger(0);
      Mutex mMutex = createMutex();
      Condition c = createCondition();
      Thread t1 = createThread([&mMutex,&c,&v]{
        AutoLock l(mMutex);
        int ret = c->wait(mMutex);
        if(ret != 0) {
          TEST_FAIL("Condition Notify Case1 test1");
          return;
        }

        v->incrementAndGet();
      });
      t1->start();

      Thread t2 = createThread([&mMutex,&c,&v]{
        AutoLock l(mMutex);
        int ret = c->wait(mMutex);
        if(ret != 0) {
          TEST_FAIL("Condition NotifyAll Case1 test2");
          return;
        }

        v->incrementAndGet();
      });
      t2->start();
      usleep(10*1000);
      c->notifyAll();
      usleep(100*1000);
      if(v->get() != 2) {
        TEST_FAIL("Condition NotifyAll Case1 test3");
      }
      c->notify();

      usleep(100*1000);
      if(v->get() != 2) {
        TEST_FAIL("Condition NotifyAll Case1 test4");
      }

      TEST_OK("Condition NotifyAll Case1 test5");
      break;
    }

}
