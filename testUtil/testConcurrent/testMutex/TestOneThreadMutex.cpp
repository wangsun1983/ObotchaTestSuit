#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

int testMutexInOneThread() {
    //Mutex()
    while(1) {
        Mutex m = createMutex();
        m->lock();
        m->lock();
        TEST_OK("[TestMutex TestMutexInOneThread case1]");
        break;
    }

    while(1) {
        Mutex m = createMutex();
        m->tryLock();
        m->lock();
        TEST_OK("[TestMutex TestMutexInOneThread case2]");
        break;
    }
    return 0;
}
