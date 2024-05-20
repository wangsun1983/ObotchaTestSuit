#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSetNextIndex() {
    while(1) {
        ByteRingArray array1 = ByteRingArray::New(5);
        array1->setNextIndex(1);
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setNextIndex case1,expect size is 1,result is %d",array1->getStoredDataSize());
        }
        
        array1->setNextIndex(2);
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setNextIndex case2");
        }
        
        array1->setNextIndex(3);
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setNextIndex case3");
        }
        
        array1->setNextIndex(4);
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setNextIndex case4");
        }
        break;
    }
    
    while(1) {
        ByteRingArray array1 = ByteRingArray::New(5);
        array1->setNextIndex(1);
        array1->setStartIndex(2);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setNextIndex case5");
        }
        
        array1->setStartIndex(3);
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setNextIndex case6");
        }
        
        array1->setStartIndex(4);
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setNextIndex case7");
        }
        
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setNextIndex case8");
        }
        break;
    }
    
    while(1) {
        ByteRingArray array1 = ByteRingArray::New(5);
        array1->setNextIndex(2);
        array1->setStartIndex(3);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setNextIndex case9");
        }
        
        array1->setStartIndex(4);
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setNextIndex case10");
        }
        
        array1->setStartIndex(0);
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setNextIndex case11");
        }
        
        array1->setStartIndex(1);
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setNextIndex case12");
        }
        break;
    }
    TEST_OK("ByteRingArray,setNextIndex case100");
}
