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
#include "AtomicNumber.hpp"

using namespace obotcha;

void testConditionWaitLambda() {
    
    while(1) {
        Mutex mu = Mutex::New();
        Condition cond = Condition::New();
        AtomicInteger value = AtomicInteger::New(1);
        
        Thread t = Thread::New([&mu,&cond,&value]{
            sleep(5);
            value->set(0);
            cond->notifyAll();
        });
        t->start();
        
        Thread t2 = Thread::New([&mu,&cond]{
            for(int i = 0;i < 20;i++) {
                usleep(1000*100);
                AutoLock l(mu);
                cond->notifyAll();
            }
        });
        t2->start();
        
        int tryCount = 0;
        
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        AutoLock l(mu);
        cond->wait(mu,[&tryCount,&value]{
            tryCount++;
            return value->get() == 0;
        });
        
        auto v = watcher->stop();
        if(v > 5005 || v < 4995) {
            TEST_FAIL("Condition Wait Lambda Case1,v is %d",v);
        }
        
        if(tryCount != 22 ) { //start 1, fail 20,success 1
            TEST_FAIL("Condition Wait Lambda Case2,tryCount is %ld",tryCount);
        }
        break;
    }
    
    while(1) {
        Mutex mu = Mutex::New();
        Condition cond = Condition::New();
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        cond->wait(mu,[]{
            return true;
        });
        auto v = watcher->stop();
        if(v > 5 || v < 0) {
            TEST_FAIL("Condition Wait Lambda Case3");
        }
        break;
    }
    
    while(1) {
        Mutex mu = Mutex::New();
        Condition cond = Condition::New();
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        AutoLock l(mu);
        cond->wait(mu,1000,[]{
            return false;
        });
        
        auto v = watcher->stop();
        if(v > 1005 || v < 1000) {
            TEST_FAIL("Condition Wait Lambda Case4,v is %d",v);
        }
        break;
    }
    
    TEST_OK("Condition Wait Lambda Case100");
}
