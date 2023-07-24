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

void TestStringSubString() {

    while(1) {
        String str = createString("abcef");
        String str2 = str->subString(0,2);
        if(!str2->sameAs("ab") || !str->sameAs("abcef")) {
            TEST_FAIL("String SubString test1");
            break;
        }

        str2 = str->subString(0,1);
        if(!str2->sameAs("a") || !str->sameAs("abcef")) {
            TEST_FAIL("String SubString test2");
            break;
        }

        str2 = str->subString(0,3);
        if(!str2->sameAs("abc") || !str->sameAs("abcef")) {
            TEST_FAIL("String SubString test3");
            break;
        }

        str2 = str->subString(0,4);
        if(!str2->sameAs("abce") || !str->sameAs("abcef")) {
            TEST_FAIL("String SubString test4");
            break;
        }

        str2 = str->subString(0,5);
        //if(!str2->sameAs("abcef") || !str->sameAs("abcef")) {
        if(!str2->sameAs("abcef") || !str->sameAs("abcef")) {
            TEST_FAIL("String SubString test5");
            break;
        }

        str2 = nullptr;

        try {
            str2 = str->subString(0,6);
        } catch(...) {}

        if(str2 != nullptr) {
            TEST_FAIL("String SubString test6");
            break;
        }

        str2 = nullptr;

        try {
            str2 = str->subString(0,-1);
        } catch(...) {}

        if(str2 != nullptr) {
            TEST_FAIL("String SubString test7");
            break;
        }

        try {
            str2 = str->subString(-1,3);
        } catch(...) {}
        
        if(str2 != nullptr) {
            TEST_FAIL("String SubString test8");
            break;
        }
        break;
    }

    TEST_OK("String SubString test100");
}
