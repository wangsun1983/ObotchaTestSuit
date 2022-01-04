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

void TestStringCharAt() {

    while(1) {
        String str = createString("abcef");
        if(str->charAt(0) != 'a'
        ||str->charAt(1) != 'b'
        ||str->charAt(2) != 'c'
        ||str->charAt(3) != 'e'
        ||str->charAt(4) != 'f') {
            TEST_FAIL("String charAt test1");
            break;
        }
        break;
    }

    while(1) {
        bool isException = false;
        String str = createString("abcef");
        try {
            str->charAt(5);
        } catch(...) {
            isException = true;
        }

        if(!isException) {
            TEST_FAIL("String charAt test2");
            break;
        }
        break;
    }

    TEST_OK("String charAt test100");
}
