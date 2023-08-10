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

void TestStringEquals() {

    while(1) {
        String str = createString(" abc  f ");
        if(!str->sameAs(" abc  f ")) {
            TEST_FAIL("String equals test1");
            break;
        }

        if(str->sameAs("a")) {
            TEST_FAIL("String equals test1_1");
            break;
        }

        if(str->sameAs("ab")) {
            TEST_FAIL("String equals test2");
            break;
        }

        if(str->sameAs("abc")) {
            TEST_FAIL("String equals test3");
            break;
        }

        if(str->sameAs("abc ")) {
            TEST_FAIL("String equals test4");
            break;
        }

        if(str->sameAs("abc  f")) {
            TEST_FAIL("String equals test5");
            break;
        }

        if(str->sameAs("     abc f      ")) {
            TEST_FAIL("String equals test6");
            break;
        }

        if(str->sameAs("A")) {
            TEST_FAIL("String equals test7");
            break;
        }

        String str2 = createString(" abc  f ");
        if(!str->equals(str2)) {
            TEST_FAIL("String equals test8");
            break;
        }

        break;
    }

    TEST_OK("String equals test100");
}
