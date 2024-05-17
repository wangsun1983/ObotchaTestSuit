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

void TestStringregionMatchesIgnoreCase() {
    while(1) {
        String str = "abc123dddff";
        if(!str->regionMatchesIgnoreCase(1,String::New("BC13333"),0,3)) {
            TEST_FAIL("String Region Matches IgnoreCase test1");
        }
        
        if(str->regionMatchesIgnoreCase(1,String::New("BC223dddff"),0,3)) {
            TEST_FAIL("String Region Matches IgnoreCase test2");
        }
        
		//bc123dddff
        if(str->regionMatchesIgnoreCase(1,String::New("BC123dddff"),0,24)) {
            TEST_FAIL("String Region Matches IgnoreCase test3");
        }
        
        /////
        if(!str->regionMatchesIgnoreCase(1,String::New("ffBC13333"),2,3)) {
            TEST_FAIL("String Region Matches IgnoreCase test4");
        }
        
        if(str->regionMatchesIgnoreCase(1,String::New("ffBC223dddff"),2,3)) {
            TEST_FAIL("String Region Matches IgnoreCase test5");
        }
        
        if(str->regionMatchesIgnoreCase(1,String::New("ffBC123dddff"),2,24)) {
            TEST_FAIL("String Region Matches IgnoreCase test6");
        }
        break;
    }
    
    TEST_OK("String Region Matches IgnoreCase test100");
}
