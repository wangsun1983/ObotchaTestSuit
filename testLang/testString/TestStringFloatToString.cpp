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
        auto str1 = createString(createFloat(1.0f),1);
        printf("str1 is %s \n",str1->toChars());
        if(!str1->equals("1.0")) {
            TEST_FAIL("String Float toString test1");
        }
        break;
    }

    TEST_OK("String Float toString test100");
}
