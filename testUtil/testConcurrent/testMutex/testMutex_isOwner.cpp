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

int testMutex_isOwner() {
    while(1) {
        Mutex m = createMutex();
        AutoLock l(m);
        if(!m->isOwner()) {
            TEST_FAIL("[TestMutex isOwner case1]");
        }
        break;
    }
    
    while(1) {
        Mutex m = createMutex();
        if(m->isOwner()) {
            TEST_FAIL("[TestMutex isOwner case2]");
        }
        break;
    }
    
    while(1) {
        Mutex m = createMutex();
        AutoLock l(m);
        
        Thread t = createThread([&m]{
            if(m->isOwner()) {
                TEST_FAIL("[TestMutex isOwner case3]");
            }
        });
        
        t->start();
        t->join();
        
        if(!m->isOwner()) {
            TEST_FAIL("[TestMutex isOwner case4]");
        }
        break;
    }
    
    while(1) {
        Mutex m = createMutex();
        
        Thread t = createThread([&m]{
            AutoLock l(m);
            sleep(1);
        });
        
        t->start();
        
        if(m->isOwner()) {
            TEST_FAIL("[TestMutex isOwner case5]");
        }
        t->join();
        break;
    }
    
    TEST_OK("[TestMutex isOwner case100]");
    return 0;
}
