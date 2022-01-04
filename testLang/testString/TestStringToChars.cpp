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

void TestStringToChars() {

    while(1) {
        String str = createString("abcdef");
        const char *p = str->toChars();
        if(strlen(p) != str->size()) {
            TEST_FAIL("String toChars test1");
            break;
        }

        if(p[0] != 'a' || p[1] != 'b' || p[2] != 'c'|| p[3] != 'd' || p[4] != 'e' ||p[5] != 'f') {
            TEST_FAIL("String toChars test2");
            break;
        }

        break;
    }
    TEST_OK("String update test100");
}
