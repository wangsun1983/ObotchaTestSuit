#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentQueue.hpp"
#include "Synchronized.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testSynchronized() {
    while(1) {
        Mutex mutex = Mutex::New();
        int run = 0;
        int loop = 0;
        
        Thread t = Thread::New([&mutex,&run,&loop]{
            TimeWatcher wa = TimeWatcher::New();
            wa->start();
            Synchronized(mutex) {
                loop++;
                st(Thread)::Sleep(200);
            }
            
            long interval = wa->stop();
            if(interval < 200 || interval > 205) {
                TEST_FAIL("[Test Synchronized case1]");
            }
            
            if(loop != 1) {
                TEST_FAIL("[Test Synchronized case2]");
            }
            run = 1;
        });
        t->start();
        
        usleep(1000*100);
        TimeWatcher watch = TimeWatcher::New();
        watch->start();
        Synchronized(mutex) {
            long interval = watch->stop();
            if(interval < 95 || interval > 105) {
                TEST_FAIL("[Test Synchronized case3]");
            }
        }
        
        t->join();
        if(run != 1) {
            TEST_FAIL("[Test Synchronized case4]");
        }
        
        break;
    }
    
    while(1) {
        Mutex mutex = Mutex::New();
        int run = 0;
        int loop = 0;
        
        Thread t = Thread::New([&mutex,&run,&loop]{
            TimeWatcher wa = TimeWatcher::New();
            wa->start();
            run = 1;
            Synchronized(mutex) {
                return;
                loop++;
            }
            run = 2;
        });
        t->start();
        t->join();
        
        if(run != 1) {
            TEST_FAIL("[Test Synchronized case5],run is %d",run);
        }

        Synchronized(mutex) {
            TEST_OK("[Test Synchronized case5]");
        }
        break;
    }
    
    TEST_OK("[Test Synchronized case100]");
}
