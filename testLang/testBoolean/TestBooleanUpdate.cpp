#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testUpdate() {

    while(1) {
        //case1
        Boolean t0 = Boolean::New(true);
        t0->update(true);
        if(!t0->toValue()) {
            TEST_FAIL("Boolean update test1");
        }

        t0->update(false);
        if(t0->toValue()) {
            TEST_FAIL("Boolean update test2");
        }

        t0 = Boolean::New(false);
        t0->update(true);
        if(!t0->toValue()) {
            TEST_FAIL("Boolean update test3");
        }

        t0 = Boolean::New(false);
        t0->update(false);
        if(t0->toValue()) {
            TEST_FAIL("Boolean update test4");
        }

        TEST_OK("Boolean update test5");
        break;
    }
    
    while(1) {
        //case1
        Boolean t0 = Boolean::New(Boolean::New(true));
        t0->update(true);
        if(!t0->toValue()) {
            TEST_FAIL("Boolean update test6");
        }

        t0->update(Boolean::New(false));
        if(t0->toValue()) {
            TEST_FAIL("Boolean update test7");
        }

        t0 = Boolean::New(Boolean::New(false));
        t0->update(true);
        if(!t0->toValue()) {
            TEST_FAIL("Boolean update test8");
        }

        t0 = Boolean::New(Boolean::New(false));
        t0->update(false);
        if(t0->toValue()) {
            TEST_FAIL("Boolean update test9");
        }

        TEST_OK("Boolean update test10");
        break;
    }

}
