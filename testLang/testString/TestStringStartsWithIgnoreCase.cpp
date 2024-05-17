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

void TestStringStartsWithIgnoreCase() {

    while(1) {
        String str = String::New("abc");
        if(!str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test1");
        }
        
        str = String::New(" abc");
        if(str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test2");
        }
        
        str = String::New("Abc");
        if(!str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test3");
        }
        
        str = String::New("A bc");
        if(str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test4");
        }
        break;
    }
    
    while(1) {
        String str = String::New("abc");
        if(!str->startsWithIgnoreCase(String::New("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test5");
        }
        
        str = String::New(" abc");
        if(str->startsWithIgnoreCase(String::New("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test6");
        }
        
        str = String::New("Abc");
        if(!str->startsWithIgnoreCase(String::New("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test7");
        }
        
        str = String::New("A bc");
        if(str->startsWithIgnoreCase(String::New("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test8");
        }
        break;
    }
    
    while(1) {
        String str = String::New("abc");
        if(!str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test9");
        }
        
        str = String::New(" abc");
        if(str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test10");
        }
        
        str = String::New("Abc");
        if(!str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test11");
        }
        
        str = String::New("A bc");
        if(str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test12");
        }
        break;
    }

    TEST_OK("String StartsWithIgnoreCase test100");
}
