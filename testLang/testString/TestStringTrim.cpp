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

void TestStringTrim() {

    while(1) {
        String str = createString(" abc f ");
        String str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abc f")) {
            TEST_FAIL("String trim test1");
            break;
        }

        str = createString("      abc f      ");
        str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abc f")) {
            TEST_FAIL("String trim test2");
            break;
        }

        str = createString("      abc   f      ");
        str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abc   f")) {
            TEST_FAIL("String trim test3");
            break;
        }

        str = createString("abc   f      ");
        str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abc   f")) {
            TEST_FAIL("String trim test4");
            break;
        }

        str = createString("    abc   f");
        str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abc   f")) {
            TEST_FAIL("String trim test5");
            break;
        }

        str = createString("abcf");
        str1 = str->trim();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trim test6");
            break;
        }

        break;
    }

    TEST_OK("String trim test100");
}
