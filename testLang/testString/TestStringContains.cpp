#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"
#include "IllegalArgumentException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestStringContains() {

    while(1) {
        String str = createString(" abc  f ");
        if(!str->contains("  ")) {
            TEST_FAIL("String contains test1");
            break;
        }

        if(!str->contains("a")) {
            TEST_FAIL("String contains test1_1");
            break;
        }

        if(!str->contains("ab")) {
            TEST_FAIL("String contains test2");
            break;
        }

        if(!str->contains("abc")) {
            TEST_FAIL("String contains test3");
            break;
        }

        if(!str->contains("abc ")) {
            TEST_FAIL("String contains test4");
            break;
        }

        if(!str->contains("abc  f")) {
            TEST_FAIL("String contains test5");
            break;
        }

        if(str->contains("     abc f      ")) {
            TEST_FAIL("String contains test6");
            break;
        }

        if(str->contains("A")) {
            TEST_FAIL("String contains test7");
            break;
        }

        break;
    }

    TEST_OK("String contains test100");
}
