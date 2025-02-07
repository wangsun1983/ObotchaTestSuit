#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testhashcode() {

    while(1) {
        //Test Construct
        Boolean t0 = Boolean::New(true);
        Boolean t0_1 = Boolean::New(true);
        if(t0->hashcode() != t0_1->hashcode()) {
          TEST_FAIL("Boolean hashcode test1 case1");
        }

        Boolean t1 = Boolean::New(true);
        Boolean t1_1 = Boolean::New(false);
        if(t1->hashcode() == t1_1->hashcode()) {
          TEST_FAIL("Boolean hashcode test case2");
        }

        Boolean t2 = Boolean::New(false);
        Boolean t2_1 = Boolean::New(false);
        if(t2->hashcode() != t2_1->hashcode()) {
          TEST_FAIL("Boolean hashcode test case3");
        }
        break;
    }

    TEST_OK("Boolean hashcode test case100");
}
