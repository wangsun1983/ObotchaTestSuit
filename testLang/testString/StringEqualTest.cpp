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

void equaltest() {

    //----------------------------
    while(1) {
        //case 1
        String str1 = createString("abc");
        String str2 = createString("abc");
        if(str1 != str2) {
            TEST_FAIL("String equaltest Special test1");
            break;
        }

        TEST_OK("String equaltest Special test2");
        break;
    }

}
