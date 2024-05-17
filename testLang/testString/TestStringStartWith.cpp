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

void TestStringStartsWith() {

    while(1) {
        String str = String::New("abc");
        if(!str->startsWith("ab")) {
            TEST_FAIL("String startsWith test1");
        }
        
        str = String::New(" abc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test2");
        }
        
        str = String::New("Abc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test3");
        }
        
        str = String::New("A bc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test4");
        }
        break;
    }
    
    while(1) {
        String str = String::New("abc");
        if(!str->startsWith(String::New("ab"))) {
            TEST_FAIL("String startsWith test5");
        }
        
        str = String::New(" abc");
        if(str->startsWith(String::New("ab"))) {
            TEST_FAIL("String startsWith test6");
        }
        
        str = String::New("Abc");
        if(str->startsWith(String::New("ab"))) {
            TEST_FAIL("String startsWith test7");
        }
        
        str = String::New("A bc");
        if(str->startsWith(String::New("ab"))) {
            TEST_FAIL("String startsWith test8");
        }
        break;
    }
    
    while(1) {
        String str = String::New("abc");
        if(!str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test9");
        }
        
        str = String::New(" abc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test10");
        }
        
        str = String::New("Abc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test11");
        }
        
        str = String::New("A bc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test12");
        }
        break;
    }

    TEST_OK("String startsWith test100");
}
