#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSetStartIndex() {
    while(1) {
        ByteRingArray array1 = createByteRingArray(5);
        array1->push(createByteArray(3));
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setStartIndex case1");
        }
        
        array1->setStartIndex(1);
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setStartIndex case2,expected is %d,result is %d",2,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(2);
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setStartIndex case3,expected is %d,result is %d",1,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(4);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setStartIndex case4,expected is %d,result is %d",4,array1->getStoredDataSize());
        }
        break;
    }
    
    while(1) {
        ByteRingArray array1 = createByteRingArray(5);
        array1->push(createByteArray(2));
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setStartIndex case1");
        }
        
        array1->setStartIndex(1);
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setStartIndex case5,expected is %d,result is %d",2,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(3);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setStartIndex case6,expected is %d,result is %d",1,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(4);
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setStartIndex case7,expected is %d,result is %d",4,array1->getStoredDataSize());
        }
        break;
    }
    
    while(1) {
        ByteRingArray array1 = createByteRingArray(5);
        array1->push(createByteArray(1));
        if(array1->getStoredDataSize() != 1) {
            TEST_FAIL("ByteRingArray,setStartIndex case8");
        }
        
        array1->setStartIndex(2);
        if(array1->getStoredDataSize() != 4) {
            TEST_FAIL("ByteRingArray,setStartIndex case9,expected is %d,result is %d",2,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(3);
        if(array1->getStoredDataSize() != 3) {
            TEST_FAIL("ByteRingArray,setStartIndex case10,expected is %d,result is %d",1,array1->getStoredDataSize());
        }
        
        array1->setStartIndex(4);
        if(array1->getStoredDataSize() != 2) {
            TEST_FAIL("ByteRingArray,setStartIndex case11,expected is %d,result is %d",4,array1->getStoredDataSize());
        }
        break;
    }
    
    TEST_OK("ByteRingArray,setStartIndex case100");
}
