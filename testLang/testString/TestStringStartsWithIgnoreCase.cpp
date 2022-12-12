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
        String str = createString("abc");
        if(!str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test1");
        }
        
        str = createString(" abc");
        if(str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test2");
        }
        
        str = createString("Abc");
        if(!str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test3");
        }
        
        str = createString("A bc");
        if(str->startsWithIgnoreCase("ab")) {
            TEST_FAIL("String StartsWithIgnoreCase test4");
        }
        break;
    }
    
    while(1) {
        String str = createString("abc");
        if(!str->startsWithIgnoreCase(createString("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test5");
        }
        
        str = createString(" abc");
        if(str->startsWithIgnoreCase(createString("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test6");
        }
        
        str = createString("Abc");
        if(!str->startsWithIgnoreCase(createString("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test7");
        }
        
        str = createString("A bc");
        if(str->startsWithIgnoreCase(createString("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test8");
        }
        break;
    }
    
    while(1) {
        String str = createString("abc");
        if(!str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test9");
        }
        
        str = createString(" abc");
        if(str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test10");
        }
        
        str = createString("Abc");
        if(!str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test11");
        }
        
        str = createString("A bc");
        if(str->startsWithIgnoreCase(std::string("ab"))) {
            TEST_FAIL("String StartsWithIgnoreCase test12");
        }
        break;
    }

    TEST_OK("String StartsWithIgnoreCase test100");
}
