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

void TestStringSize() {

    while(1) {
        String str = String::New(" abc f ");
        if(str->size() != 7) {
            TEST_FAIL("String size test1");
            break;
        }

        char buff[12] = {0};
        buff[0] = 'a';
        buff[1] = 'b';
        buff[3] = 'd';
        buff[4] = 'f';
        str = String::New(buff);
        if(str->size() != 2) {
            TEST_FAIL("String size1 test2");
            break;
        }
        break;
    }

    TEST_OK("String size test100");
}
