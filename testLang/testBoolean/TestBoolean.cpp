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
#include "String.hpp"

using namespace obotcha;

void basetest() {

    while(1) {
        //Test Construct
        Boolean t0 = createBoolean(true);
        Boolean t0_1 = createBoolean(t0);

        if(t0 != t0_1){
            TEST_FAIL("Boolean construct test1");
        }

        Boolean t1 = createBoolean(createString("true"));
        if(!t1->toValue()) {
            TEST_FAIL("Boolean construct test2");
        }

        Boolean t2 = createBoolean(createString("false"));
        if(t2->toValue()) {
            TEST_FAIL("Boolean construct test3");
        }

        Boolean t3 = createBoolean(createString("TrUe"));
        if(!t3->toValue()) {
            TEST_FAIL("Boolean construct test4");
        }

        Boolean t4 = createBoolean(createString("tRUe"));
        if(!t4->toValue()) {
            TEST_FAIL("Boolean construct test5");
        }

        Boolean t5 = createBoolean(createString("False"));
        if(t5->toValue()) {
            TEST_FAIL("Boolean construct test6");
        }

        Boolean t6 = createBoolean(createString("FAlse "));
        if(t6->toValue()) {
            TEST_FAIL("Boolean construct test6");
        }

        Boolean t7 = createBoolean(createString("t r u e "));
        if(!t7->toValue()) {
            TEST_FAIL("Boolean construct test7");
        }

        Boolean t8 = createBoolean(createString("f a L S e"));
        if(t8->toValue()) {
            TEST_FAIL("Boolean construct test8");
        }

        bool isException = false;
        try {
          Boolean t9 = createBoolean(createString("abc"));
        } catch(InitializeException exception) {
          isException = true;
        }

        if(!isException) {
            TEST_FAIL("Boolean construct test9");
        }

        TEST_OK("Boolean construct test");
        break;
    }

     while(1) {
        //Test Construct
        Boolean t0 = createBoolean(true);
        Boolean t0_1 = createBoolean(t0);

        if(t0 != t0_1){
            TEST_FAIL("Boolean construct test10");
        }

        Boolean t1 = createBoolean("true");
        if(!t1->toValue()) {
            TEST_FAIL("Boolean construct test11");
        }

        Boolean t2 = createBoolean("false");
        if(t2->toValue()) {
            TEST_FAIL("Boolean construct test12");
        }

        Boolean t3 = createBoolean("TrUe");
        if(!t3->toValue()) {
            TEST_FAIL("Boolean construct test13");
        }

        Boolean t4 = createBoolean("tRUe");
        if(!t4->toValue()) {
            printf("Boolean construct test14");
        }

        Boolean t5 = createBoolean("False");
        if(t5->toValue()) {
            TEST_FAIL("Boolean construct test15");
        }

        Boolean t6 = createBoolean("FAlse ");
        if(t6->toValue()) {
            TEST_FAIL("Boolean construct test16");
        }

        Boolean t7 = createBoolean("t r u e ");
        if(!t7->toValue()) {
            TEST_FAIL("Boolean construct test17");
        }

        Boolean t8 = createBoolean("f a L S e");
        if(t8->toValue()) {
            TEST_FAIL("Boolean construct test18");
        }

        bool isException = false;
        try {
          Boolean t9 = createBoolean("abc");
        } catch(InitializeException exception) {
          isException = true;
        }

        if(!isException) {
            TEST_FAIL("Boolean construct test19");
        }

        TEST_OK("Boolean construct test20");
        break;
    }

    //Test bool equals(Boolean p);
    while(1){
        Boolean t1 = createBoolean(false);
        Boolean t2 = createBoolean(false);
        Boolean t3 = createBoolean(true);

        if(!t1->equals(t2)) {
            TEST_FAIL("Boolean equal test1");
        }

        if(t1 != t2){
            TEST_FAIL("Boolean operator test2");
        }

        if(t2->equals(t3)) {
            TEST_FAIL("Boolean equal test3");
        }

        if(t2 == t3) {
            TEST_FAIL("Boolean equal test4");
        }

        if(t2 == nullptr) {
            TEST_FAIL("Boolean equal test5");
        }

        if(!t1->equals(createBoolean(false)) 
			|| !t2->equals(createBoolean(false)) 
			|| !t3->equals(createBoolean(true))) {
            TEST_FAIL("Boolean equal test6");
        }
		
		if(!t1->sameAs(false)
			|| !t2->sameAs(false) 
			|| !t3->sameAs(true)) {
		    TEST_FAIL("Boolean equal test7");
		}

        TEST_OK("Boolean equal test");
        break;
    }
}
