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

void TestHexInt() {

    //----------------------------
    while(1) {
        //case 1
        String str1 = String::New("0x11");
        
        if(str1->toHexInt()->toValue() != 17) {
            TEST_FAIL("String toHexInt test1");
            break;
        }
        
        str1 = String::New("31");
        if(str1->toHexInt()->toValue() != 49) {
            TEST_FAIL("String toHexInt test2");
            break;
        }
        break;
    }

    TEST_OK("String toHexInt test100");
}
