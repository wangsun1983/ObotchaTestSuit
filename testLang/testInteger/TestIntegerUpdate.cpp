#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIntegerUpdate() {
     
    Integer v1 = Integer::New(100);
    Integer v2 = Integer::New(200);
    v1->update(v2);
    if(v1->toValue() != 200) {
        TEST_FAIL("Integer testIntegerUpdate test1");
    }
    
    TEST_OK("Integer testIntegerUpdate test100");
}
