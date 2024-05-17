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

void testStringFind() {
    String abc = String::New("i aa ibd ii");
    int index = abc->find("i");
    if(index != 0) {
        TEST_FAIL("String Find test1");
    }
    
    index = abc->find("i",index+1);
    if(index != 5) {
        TEST_FAIL("String Find test2");
    }

    index = abc->find("i",index+1);
    if(index != 9) {
        TEST_FAIL("String Find test3");
    }

    index = abc->find("i",index+1);
    if(index != 10) {
        TEST_FAIL("String Find test4");
    }

    index = abc->find("i",index+1);
    if(index != -1) {
        TEST_FAIL("String Find test5");
    }

    abc = String::New("1{{ i {{ ibd {{");
    index = abc->find("{{",0);
    if(index != 1) {
        TEST_FAIL("String Find test6");
    }

    index = abc->find("{{",index+1);
    if(index != 6) {
        TEST_FAIL("String Find test7");
    }

    index = abc->find("{{",index+1);
    if(index != 13) {
        TEST_FAIL("String Find test8");
    }

    TEST_OK("String Find test100");
}
