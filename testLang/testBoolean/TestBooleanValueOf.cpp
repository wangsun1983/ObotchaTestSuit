#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testparse() {

    while(1) {

        Boolean t1 = st(Boolean)::parse("true");
        if(!t1->toValue()) {
            TEST_FAIL("Boolean parse test1");
        }

        Boolean t2 = st(Boolean)::parse("false");
        if(t2->toValue()) {
            TEST_FAIL("Boolean parse test2");
        }

        Boolean t3 = st(Boolean)::parse("TrUe");
        if(!t3->toValue()) {
            TEST_FAIL("Boolean parse test3");
        }

        Boolean t4 = st(Boolean)::parse("tRUe");
        if(!t4->toValue()) {
            TEST_FAIL("Boolean parse test4");
        }

        Boolean t5 = st(Boolean)::parse("False");
        if(t5->toValue()) {
            TEST_FAIL("Boolean parse test5");
        }

        Boolean t6 = st(Boolean)::parse("FAlse ");
        if(t6->toValue()) {
            TEST_FAIL("Boolean parse test6");
        }

        Boolean t7 = st(Boolean)::parse("t r u e ");
        if(!t7->toValue()) {
            TEST_FAIL("Boolean parse test7");
        }

        Boolean t8 = st(Boolean)::parse("f a L S e");
        if(t8->toValue()) {
            TEST_FAIL("Boolean parse test8");
        }

        Boolean t9 = st(Boolean)::parse("abc");
        if(t9 != nullptr) {
            TEST_FAIL("Boolean parse test9");
        }

        TEST_OK("Boolean parse test19");
        break;
    }

}
