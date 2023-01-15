#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "NullPointerException.hpp"
#include "TransformException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestStringStaticIgnoreCase() {

    if(!st(String)::isEqualsIgnoreCase("abc","AbC")) {
        TEST_FAIL("String static isEqualsIgnoreCase test1");
    }

    if(st(String)::isEqualsIgnoreCase("abc","Abd")) {
        TEST_FAIL("String static isEqualsIgnoreCase test2");
    }
    
    if(!st(String)::isEqualsIgnoreCase("abc","Abf",2)) {
        TEST_FAIL("String static isEqualsIgnoreCase test3");
    }
    
    if(st(String)::isEqualsIgnoreCase("abc","Abcd",4)) {
        TEST_FAIL("String static isEqualsIgnoreCase test4");
    }
    TEST_OK("String static isEqualsIgnoreCase test100");
}
