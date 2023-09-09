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

void TestStringFloatToString() {

    while(1) {
        auto str1 = createString(createFloat(1.01f),5);
        if(!str1->sameAs("1.01")) {
            TEST_FAIL("String Float toString test1,str is %s",str1->toChars());
        }
        break;
    }

    TEST_OK("String Float toString test100");
}
