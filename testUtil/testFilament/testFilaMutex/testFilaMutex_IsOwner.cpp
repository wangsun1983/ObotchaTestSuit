#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"

using namespace std;
using namespace obotcha;

void testFilaMutexIsOwner() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        
        FilaMutex mutex = createFilaMutex();
        int testCount = 0;
        
        croutine->execute([&mutex,&testCount] {
            AutoLock l(mutex);
            //mutex->lock();
            poll(NULL, 0, 200);
            if(!mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case1");
            }
            testCount++;
        });
        
        usleep(100*1000);
        croutine->execute([&mutex,&testCount] {
            if(mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case2");
            }
            
            testCount++;
        });
        
        usleep(300*1000);
        if(testCount != 2) {
            TEST_FAIL("FilaMutex test isOwner case3,testCount is %d",testCount);
        }
        croutine->shutdown();
        croutine->awaitTermination();
        break;
    }
    
    while(1) {
        FilaMutex m = createFilaMutex();
        if(m->isOwner()) {
            TEST_FAIL("FilaMutex test isOwner case4");
        }
        break;
    }
    
    while(1) {
        FilaMutex m = createFilaMutex();
        AutoLock l(m);
        if(!m->isOwner()) {
            TEST_FAIL("FilaMutex test isOwner case5");
        }
        break;
    }
    
    while(1) {
        FilaMutex mutex = createFilaMutex();
        
        Thread t = createThread([&mutex]{
            AutoLock l(mutex);
            usleep(100*1000);
            if(!mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case6");
            }
        });
        
        t->start();
        
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        usleep(1000);
        croutine->execute([&mutex] {
            if(mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case7");
            }
        });
        
        t->join();
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }
    
    while(1) {
        FilaMutex mutex = createFilaMutex();
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
    
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            if(!mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case8");
            }
            usleep(200*1000);
        });
        
        usleep(100*1000);
        Thread t = createThread([&mutex]{
            if(mutex->isOwner()) {
                TEST_FAIL("FilaMutex test isOwner case9");
            }
        });
        t->start();
        
        t->join();
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }
    
    TEST_OK("FilaMutex test isOwner case100");
}
