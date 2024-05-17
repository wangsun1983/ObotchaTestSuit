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

void testConditionWaitWithoutLock() {
    Mutex m = Mutex::New();
    Condition c = Condition::New();
    
    try {
        c->wait(m);
        TEST_FAIL("Condition Wait Witchout Lock Case1");
    } catch(...) {
    }
    
    try {
        c->wait(m,1000);
        TEST_FAIL("Condition Wait Witchout Lock Case2");
    } catch(...) {
    }
    
    try {
        c->wait(m,1000,[]{return false;});
        TEST_FAIL("Condition Wait Witchout Lock Case3");
    } catch(...) {
    }
    
    try {
        c->wait(m,1000,[]{return true;});
        TEST_FAIL("Condition Wait Witchout Lock Case4");
    } catch(...) {
    }
    
    TEST_OK("Condition Wait Witchout Lock Case100");
}
