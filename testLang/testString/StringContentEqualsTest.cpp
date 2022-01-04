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

void StringContentEqualsTest() {

    while(1) {
        String a = "a";
        String b = "a";
        if(!st(String)::contentEquals(a,b)) {
            TEST_FAIL("String ContentEquals test1");
            break;
        }

        String a1 = "a";
        String b1 = "b";
        if(st(String)::contentEquals(a1,b1)) {
            TEST_FAIL("String ContentEquals test2");
            break;
        }

        String a2 = "a";
        String b2 = nullptr;
        if(st(String)::contentEquals(a2,b2)) {
            TEST_FAIL("String ContentEquals test3");
            break;
        }

        String a3 = nullptr;
        String b3 = "a";
        if(st(String)::contentEquals(a3,b3)) {
            TEST_FAIL("String ContentEquals test4");
            break;
        }

        String a4 = nullptr;
        String b4 = nullptr;
        if(!st(String)::contentEquals(a4,b4)) {
            TEST_FAIL("String ContentEquals test5");
            break;
        }

        break;
    }


    while(1) {
        String a = "abc";
        String b = "ABC";
        if(!st(String)::contentEqualsIgnoreCase(a,b)) {
            TEST_FAIL("String ContentEquals test6");
            break;
        }

        String a1 = "ABC";
        String b1 = "ABC";
        if(!st(String)::contentEqualsIgnoreCase(a1,b1)) {
            TEST_FAIL("String ContentEquals test7");
            break;
        }

        String a2 = "ABC";
        String b2 = nullptr;
        if(st(String)::contentEqualsIgnoreCase(a2,b2)) {
            TEST_FAIL("String ContentEquals test8");
            break;
        }

        String a3 = nullptr;
        String b3 = "a";
        if(st(String)::contentEqualsIgnoreCase(a3,b3)) {
            TEST_FAIL("String ContentEquals test9");
            break;
        }

        String a4 = nullptr;
        String b4 = nullptr;
        if(!st(String)::contentEqualsIgnoreCase(a4,b4)) {
            TEST_FAIL("String ContentEquals test10");
            break;
        }

        break;
    }

    TEST_OK("String ContentEquals test100");
}
