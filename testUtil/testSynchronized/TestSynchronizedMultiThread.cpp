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

void testSynchronizedMultiThread() {
    while(1) {
        Mutex mutex = createMutex();
        int run = 0;
        int run2 = 0;
        int loop = 0;
        
        Thread t1 = createThread([&mutex,&run]{
            usleep(1000*100);
            TimeWatcher watch = createTimeWatcher();
            watch->start();
            Synchronized(mutex) {
                run++;
            }
            long interval = watch->stop();
            if(interval > 205 || interval < 195) {
                TEST_FAIL("[Test Synchronized MultiThread case1]");
            }
        });
        t1->start();

        Thread t2 = createThread([&mutex,&run2]{
            usleep(1000*200);
            mutex->unlock();
            run2++;
        });
        t2->start();

        Synchronized(mutex) {
            usleep(1000*300);
        }
        t1->join();
        t2->join();

        if(run != 1 || run2 != 1) {
            TEST_FAIL("[Test Synchronized MultiThread case2],run is %d,run2 is %d",run,run2);
        }
        
        break;
    }
    
    
    TEST_OK("[Test Synchronized MultiThread case100]");
}
