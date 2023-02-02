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

void TestOctInt() {

    //----------------------------
    while(1) {
        //case 1
        String str1 = createString("11");
        
        if(str1->toOctInt()->toValue() != 9) {
            TEST_FAIL("String toOctInt test1");
            break;
        }
        
        str1 = createString("31");
        if(str1->toOctInt()->toValue() != 25) {
            TEST_FAIL("String toOctInt test2");
            break;
        }
        break;
    }

    TEST_OK("String toOctInt test100");
}
