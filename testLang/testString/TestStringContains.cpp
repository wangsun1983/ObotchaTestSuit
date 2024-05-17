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

void TestStringContains() {

    while(1) {
        String str = String::New(" abc  f ");
        if(!str->contains("  ")) {
            TEST_FAIL("String contains test1");
            break;
        }

        if(!str->contains("a")) {
            TEST_FAIL("String contains test1_1");
            break;
        }

        if(!str->contains("ab")) {
            TEST_FAIL("String contains test2");
            break;
        }

        if(!str->contains("abc")) {
            TEST_FAIL("String contains test3");
            break;
        }

        if(!str->contains("abc ")) {
            TEST_FAIL("String contains test4");
            break;
        }

        if(!str->contains("abc  f")) {
            TEST_FAIL("String contains test5");
            break;
        }

        if(str->contains("     abc f      ")) {
            TEST_FAIL("String contains test6");
            break;
        }

        if(str->contains("A")) {
            TEST_FAIL("String contains test7");
            break;
        }

        break;
    }
    
    while(1) {
        String str = String::New(" abc  f ");
        const String str1 = String::New("  ");
        if(!str->contains(str1)) {
            TEST_FAIL("String contains test8");
            break;
        }
        
        const String str2 = String::New("a");
        if(!str->contains(str2)) {
            TEST_FAIL("String contains test9");
            break;
        }
        
        const String str3 = String::New("ab");
        if(!str->contains(str3)) {
            TEST_FAIL("String contains test10");
            break;
        }
        
        const String str4 = String::New("abc");
        if(!str->contains(str4)) {
            TEST_FAIL("String contains test11");
            break;
        }
        
        const String str5 = String::New("abc ");
        if(!str->contains(str5)) {
            TEST_FAIL("String contains test12");
            break;
        }
        
        const String str5_1 = String::New("abc  f");
        if(!str->contains(str5_1)) {
            TEST_FAIL("String contains test13");
            break;
        }
        
        const String str6 = String::New("     abc f      ");
        if(str->contains(str6)) {
            TEST_FAIL("String contains test14");
            break;
        }
        
        const String str7 = String::New("A");
        if(str->contains(str7)) {
            TEST_FAIL("String contains test15");
            break;
        }

        break;
    }

    TEST_OK("String contains test100");
}
