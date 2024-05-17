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

void testConditionGetCount() {
    while(1) {
      Condition cond = Condition::New();
      Mutex mu = Mutex::New();
      
      Thread t1 = Thread::New([&]{
          AutoLock l(mu);
          cond->wait(l);
      });
      t1->start();
      
      Thread t2 = Thread::New([&]{
          AutoLock l(mu);
          cond->wait(mu);
      });
      t2->start();
      
      int count_t3 = 0;
      Thread t3 = Thread::New([&]{
          AutoLock l(mu);
          cond->wait(mu,[&]{
            if(count_t3 == 0) {
                count_t3++;
                return false;
            }
            return true;
          });
      });
      t3->start();
      
      int count_t4 = 0;
      Thread t4 = Thread::New([&]{
          AutoLock l(mu);
          cond->wait(l,[&]{
            if(count_t4 == 0) {
                count_t4++;
                return false;
            }
            return true;
          });
      });
      t4->start();
      
      int count_t5 = 0;
      Thread t5= Thread::New([&]{
          AutoLock l(mu);
          cond->wait(l,0,[&]{
            if(count_t5 == 0) {
                count_t5++;
                return false;
            }
            return true;
          });
      });
      t5->start();
      
      int count_t6 = 0;
      Thread t6= Thread::New([&]{
          AutoLock l(mu);
          cond->wait(mu,0,[&]{
            if(count_t6 == 0) {
                count_t6++;
                return false;
            }
            return true;
          });
      });
      t6->start();
      usleep(100*1000);
      if(cond->getWaitCount() != 6) {
        TEST_FAIL("Condition GetCount Case1,count is %d",cond->getWaitCount());
      }
      cond->notifyAll();
      t1->join();
      t2->join();
      t3->join();
      t4->join();
      t5->join();
      t6->join();
      break;
    }
    
    TEST_OK("Condition GetCount Case100");
}
