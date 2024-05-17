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

void TestStringHashcode() {

    while(1) {
        String str = String::New(" abc  f ");
        String str2 = String::New(" abc  f ");
        if(str->hashcode() != str2->hashcode()) {
            TEST_FAIL("String hashcode test1");
            break;
        }
        
        String str3 = String::New("a");
        if(str->hashcode() == str3->hashcode()) {
            TEST_FAIL("String hashcode test1_1");
            break;
        }
        String str4 = String::New("ab");
        if(str->hashcode() == str4->hashcode()) {
            TEST_FAIL("String hashcode test2");
            break;
        }
        String str5 = String::New("ab");
        if(str->hashcode() == str5->hashcode()) {
            TEST_FAIL("String hashcode test3");
            break;
        }
        
        String str6 = String::New("abc ");
        if(str->hashcode() == str6->hashcode()) {
            TEST_FAIL("String hashcode test4");
            break;
        }
        
        String str7 = String::New("abc  f");
        if(str->hashcode() == str7->hashcode()) {
            TEST_FAIL("String hashcode test5");
            break;
        }
        
        String str8 = String::New("abc  f");
        if(str->hashcode() == str8->hashcode()) {
            TEST_FAIL("String hashcode test6");
            break;
        }
        
        String str9 = String::New("A");
        if(str->hashcode() == str9->hashcode()) {
            TEST_FAIL("String hashcode test7");
            break;
        }
        
        String str10 = String::New(" abc  f ");
        if(str->hashcode() != str10->hashcode()) {
            TEST_FAIL("String hashcode test8");
            break;
        }

        break;
    }

    TEST_OK("String hashcode test100");
}
