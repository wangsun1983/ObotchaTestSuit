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

void TestStringTrimAll() {

    while(1) {
        String str = String::New(" abc f ");
        String str1 = str->trimAll();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trimAll test1");
            break;
        }

        str = String::New("      abc f      ");
        str1 = str->trimAll();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trimAll test2");
            break;
        }

        str = String::New("      abc   f      ");
        str1 = str->trimAll();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trimAll test3");
            break;
        }

        str = String::New("abc   f      ");
        str1 = str->trimAll();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trimAll test4");
            break;
        }

        str = String::New("    abc   f");
        str1 = str->trimAll();
        if(str1 == nullptr || !str1->sameAs("abcf")) {
            TEST_FAIL("String trimAll test5");
            break;
        }

        break;
    }

    TEST_OK("String trimAll test100");
}
