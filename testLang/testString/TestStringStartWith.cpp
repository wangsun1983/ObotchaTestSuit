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
        String str = createString("abc");
        if(!str->startsWith("ab")) {
            TEST_FAIL("String startsWith test1");
        }
        
        str = createString(" abc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test2");
        }
        
        str = createString("Abc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test3");
        }
        
        str = createString("A bc");
        if(str->startsWith("ab")) {
            TEST_FAIL("String startsWith test4");
        }
        break;
    }
    
    while(1) {
        String str = createString("abc");
        if(!str->startsWith(createString("ab"))) {
            TEST_FAIL("String startsWith test5");
        }
        
        str = createString(" abc");
        if(str->startsWith(createString("ab"))) {
            TEST_FAIL("String startsWith test6");
        }
        
        str = createString("Abc");
        if(str->startsWith(createString("ab"))) {
            TEST_FAIL("String startsWith test7");
        }
        
        str = createString("A bc");
        if(str->startsWith(createString("ab"))) {
            TEST_FAIL("String startsWith test8");
        }
        break;
    }
    
    while(1) {
        String str = createString("abc");
        if(!str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test9");
        }
        
        str = createString(" abc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test10");
        }
        
        str = createString("Abc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test11");
        }
        
        str = createString("A bc");
        if(str->startsWith(std::string("ab"))) {
            TEST_FAIL("String startsWith test12");
        }
        break;
    }

    TEST_OK("String startsWith test100");
}
