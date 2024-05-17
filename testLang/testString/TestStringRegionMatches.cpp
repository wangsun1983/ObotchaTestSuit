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

void TestStringRegionMatches() {
    while(1) {
        String str = "abc123dddff";
        if(!str->regionMatches(1,String::New("bc13333"),0,3)) {
            TEST_FAIL("String Region Matches test1");
        }
        
        if(str->regionMatches(1,String::New("bc223dddff"),0,3)) {
            TEST_FAIL("String Region Matches test2");
        }
        
        if(str->regionMatches(1,String::New("bc123dddff"),0,24)) {
            TEST_FAIL("String Region Matches test3");
        }
        
        /////
        if(!str->regionMatches(1,String::New("ffbc13333"),2,3)) {
            TEST_FAIL("String Region Matches test4");
        }
        
        if(str->regionMatches(1,String::New("ffbc223dddff"),2,3)) {
            TEST_FAIL("String Region Matches test5");
        }
        
        if(str->regionMatches(1,String::New("ffbc123dddff"),2,24)) {
            TEST_FAIL("String Region Matches test6");
        }
        break;
    }
    
    TEST_OK("String Region Matches test100");
}
