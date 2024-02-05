#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "DateTime.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "TimeZone.hpp"

using namespace obotcha;

void testGetZone() {
    if(st(TimeZone)::GetZone() != 8) {
        TEST_FAIL("[TimeZone Test GetZone case1]");
    }
    
    TEST_OK("[TimeZone Test GetZone case100]");
}
