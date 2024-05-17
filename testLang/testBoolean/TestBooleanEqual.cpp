#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testequals() {

    while(1) {
        //case1
        Boolean t0 = Boolean::New(true);
        Boolean t0_1 = Boolean::New(true);
        //Boolean t2 = Boolean::New(nullptr);

        if(t0 != t0_1){
            TEST_FAIL("Boolean special equal test1");
        }

        //case1
        Boolean t1 = Boolean::New(false);
        Boolean t1_1 = Boolean::New(false);
        if(t1 != t1_1){
            TEST_FAIL("Boolean special equal test2");
        }

        //case1
        Boolean t2 = Boolean::New(false);
        Boolean t2_1 = Boolean::New(true);
        if(t2 == t2_1){
            TEST_FAIL("Boolean special equal test3");
        }

        TEST_OK("Boolean special equal test4");
        break;
    }

    while(1) {
        //case1
        Boolean t0 = Boolean::New(true);
        Boolean t0_1 = Boolean::New(true);
        //Boolean t2 = Boolean::New(nullptr);

        if(!t0->equals(t0_1)){
            TEST_FAIL("Boolean equal test1");
        }

        t0 = Boolean::New(true);
        t0_1 = Boolean::New(false);

        if(t0->equals(t0_1)){
            TEST_FAIL("Boolean equal test2");
        }

        t0 = Boolean::New(true);
        if(!t0->equals(Boolean::New(true))) {
            TEST_FAIL("Boolean equal test3");
        }

        t0 = Boolean::New(false);
        if(!t0->equals(Boolean::New(false))) {
            TEST_FAIL("Boolean equal test4");
        }

        TEST_OK("Boolean equal test5");
        break;
    }
	
	while(1) {
		auto v1 = Boolean::New(false);
		auto v2 = Boolean::New(false);
		if(v1 != v2) {
			TEST_FAIL("Boolean equal test6");
		}
		
		v1 = Boolean::New(true);
		v2 = Boolean::New(true);
		if(v1 != v2) {
			TEST_FAIL("Boolean equal test7");
		}
		
		v1 = Boolean::New(true);
		v2 = Boolean::New(false);
		if(v1 == v2) {
			TEST_FAIL("Boolean equal test8");
		}
		break;
	}
	TEST_OK("Boolean equal test100");
}
