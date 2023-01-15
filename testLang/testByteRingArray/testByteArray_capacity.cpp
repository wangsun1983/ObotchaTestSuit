#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testByteArrayCapacity() {
    
    ByteRingArray array = createByteRingArray(16);
    if(array->getCapacity() != 16) {
        TEST_FAIL("---[ByteRingArray Test Capacity case1]");
    }
    
    array->push(1);
    if(array->getCapacity() != 16) {
        TEST_FAIL("---[ByteRingArray Test Capacity case2]");
    }
    
    array->push(1);
    array->push(1);
    array->push(1);
    array->popAll();
    if(array->getCapacity() != 16) {
        TEST_FAIL("---[ByteRingArray Test Capacity case3]");
    }
    
    TEST_OK("---[ByteRingArray Test Capacity case100]");
}