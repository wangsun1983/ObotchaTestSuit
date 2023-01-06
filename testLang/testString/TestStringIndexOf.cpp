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

void TestStringIndexOf() {

    while(1) {
        String str = createString(" abc  f ");
        if(str->indexOf("  ") != 4) {
            TEST_FAIL("String indexOf test1");
            break;
        }

        if(str->indexOf("a") != 1) {
            TEST_FAIL("String indexOf test1_1");
            break;
        }

        if(str->indexOf("ab") != 1) {
            TEST_FAIL("String indexOf test2");
            break;
        }

        if(str->indexOf("abc") != 1) {
            TEST_FAIL("String indexOf test3");
            break;
        }

        if(str->indexOf("abc ") != 1) {
            TEST_FAIL("String indexOf test4");
            break;
        }

        if(str->indexOf("abc  f") != 1) {
            TEST_FAIL("String indexOf test5");
            break;
        }

        if(str->indexOf("     abc f      ") != -1) {
            TEST_FAIL("String indexOf test6");
            break;
        }

        if(str->indexOf("A") != -1) {
            TEST_FAIL("String indexOf test7");
            break;
        }

        if(str->indexOf('a') != 1) {
            TEST_FAIL("String indexOf test8");
            break;
        }

        if(str->indexOf('b') != 2) {
            TEST_FAIL("String indexOf test9");
            break;
        }

        if(str->indexOf(' ') != 0) {
            TEST_FAIL("String indexOf test10");
            break;
        }

        break;
    }
    
    while(1) {
        String str = createString("abCDe fg");
        if(str->indexOfIgnoreCase("cde",2) != 2) {
            TEST_FAIL("String indexOf test11");
            break;
        }
        
        if(str->indexOfIgnoreCase("fcde",2) != -1) {
            TEST_FAIL("String indexOf test12");
            break;
        }
        break;
    }
    
    while(1) {
        String str = createString("abCDe fg");
        if(str->indexOfIgnoreCase("cde") != 2) {
            TEST_FAIL("String indexOf test13");
            break;
        }
        
        if(str->indexOfIgnoreCase("fcde") != -1) {
            TEST_FAIL("String indexOf test13");
            break;
        }
        break;
    }


    TEST_OK("String indexOf test100");
}
