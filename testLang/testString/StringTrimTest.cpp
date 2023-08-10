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

void trimtest() {

    //String trim();
    while(1) {
        //case1
        String string1 = "a b c";
        String string1_1 = string1->trim();
        if(!string1_1->sameAs("a b c")) {
            TEST_FAIL("String trim Special test1");
        }

        if(!string1->sameAs("a b c")) {
            TEST_FAIL("String trim Special test1_1");
        }

        //case2
        String string2 = " a b c";
        String string2_1 = string2->trim();
        if(!string2_1->sameAs("a b c")) {
            TEST_FAIL("String trim Special test2");
            break;
        }

        if(!string2->sameAs(" a b c")) {
            TEST_FAIL("String trim Special test2_1");
        }

        //case3
        String string3 = " a b c ";
        String string3_1 = string3->trim();
        if(!string3_1->sameAs("a b c")) {
            TEST_FAIL("String trim Special test3");
            break;
        }

        if(!string3->sameAs(" a b c ")) {
            TEST_FAIL("String trim Special test3_1");
        }

        TEST_OK("String trim Special test12");
        break;
    }

    //String trimAll();
     while(1) {
        //case1
        String string1 = "a b c";
        String string1_1 = string1->trimAll();
        if(!string1_1->sameAs("abc")) {
            TEST_FAIL("String trimAll Special test1");
        }

        if(!string1->sameAs("a b c")) {
            TEST_FAIL("String trimAll Special test1_1");
        }

        //case2
        String string2 = " a b c";
        String string2_1 = string2->trimAll();
        if(!string2_1->sameAs("abc")) {
            TEST_FAIL("String trimAll Special test2");
            break;
        }

        if(!string2->sameAs(" a b c")) {
            TEST_FAIL("String trimAll Special test2_1");
        }

        //case3
        String string3 = " a b c ";
        String string3_1 = string3->trimAll();
        if(!string3_1->sameAs("abc")) {
            TEST_FAIL("String trimAll Special test3");
            break;
        }

        if(!string3->sameAs(" a b c ")) {
            TEST_FAIL("String trimAll Special test3_1");
        }

        TEST_OK("String trimAll Special test12");
        break;
    }
}
