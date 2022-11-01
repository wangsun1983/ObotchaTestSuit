#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "InterruptedException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadStatus() {
    //TestThread onInterrupt case1
    while(1) {
        auto thread = createThread([]{
           usleep(100); 
        });
        
        if(thread->getStatus() != st(Thread)::NotStart) {
            TEST_FAIL("[Thread Test {getStatus()} case1],status is %d",thread->getStatus());
        }
        break;
    }
    
    while(1) {
        auto thread = createThread([]{
           usleep(100*1000); 
        });
        thread->start();
        
        usleep(100);
        if(thread->getStatus() != st(Thread)::Running) {
            TEST_FAIL("[Thread Test {getStatus()} case2],status is %d",thread->getStatus());
        
        }
        thread->join();
        break;
    }
    
    while(1) {
        auto thread = createThread([]{
           usleep(100); 
        });
        thread->start();
        
        usleep(200);
        if(thread->getStatus() != st(Thread)::Complete) {
            TEST_FAIL("[Thread Test {getStatus()} case2],status is %d",thread->getStatus());
        
        }
        thread->join();
        break;
    }
    
    while(1) {
        auto thread = createThread([]{
           usleep(500); 
        });
        thread->start();
        
        usleep(100);
        thread->interrupt();
        if(thread->getStatus() != st(Thread)::Interrupting) {
            TEST_FAIL("[Thread Test {getStatus()} case3],status is %d",thread->getStatus());
        
        }
        thread->join();
        break;
    }

    TEST_OK("[Thread Test {getStatus()} case100]");

}
