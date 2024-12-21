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

void TestStringEndsWith() {

    String case1_str = String::New("");
    if(case1_str->endsWith("abc")) {
        TEST_FAIL("String Endswith test1");
    }
    
    String case2_str = String::New("ab");
    if(case2_str->endsWith("abc")) {
        TEST_FAIL("String Endswith test2");
    }
    
    String case3_str = String::New("abc");
    if(!case3_str->endsWith("abc")) {
        TEST_FAIL("String Endswith test3");
    }
    
    String case4_str = String::New("abc ");
    if(case4_str->endsWith("abc")) {
        TEST_FAIL("String Endswith test4");
    }
    
    String case5_str = String::New("abc");
    if(case5_str->endsWith("f")) {
        TEST_FAIL("String Endswith test5");
    }
    
    TEST_OK("String Endswith test100");
}
