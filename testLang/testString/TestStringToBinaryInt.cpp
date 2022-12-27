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

void TestBinaryInt() {

    //----------------------------
    while(1) {
        //case 1
        String str1 = createString("0b11");
        
        if(str1->toBinaryInt()->toValue() != 3) {
            TEST_FAIL("String toBinaryInt test1");
            break;
        }
        
        str1 = createString("010");
        if(str1->toBinaryInt()->toValue() != 2) {
            TEST_FAIL("String toBinaryInt test2");
            break;
        }
        break;
    }
    
    while(1) {
        //case 1
        String str1 = createString("0b51");
        
        if(str1->toBinaryInt() != nullptr) {
            TEST_FAIL("String toBinaryInt test3");
        }
        break;
    }

    TEST_OK("String TestBinaryInt test100");
}
