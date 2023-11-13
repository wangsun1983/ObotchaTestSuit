#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include <string.h>
#include "TestLog.hpp"

using namespace obotcha;


void testSetIndex() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    ByteArray testData = createByteArray(array,8);
    ByteArrayReader reader = createByteArrayReader(testData);
    reader->setIndex(1);
    if(reader->getIndex() != 1) {
        TEST_FAIL("[TestByteArrayReader setIndex case1],index is %d",reader->getIndex());
    }
    
    int value1 = reader->read<int>();
    int value2 = 0x02|0x03<<8|0x04<<16|0x05<<24;
    if(value2 != value1) {
        TEST_FAIL("[TestByteArrayReader setIndex case2],v is %d,v2 is %d",value1,value2);
    }
    
    if(reader->getIndex() != 5) {
        TEST_FAIL("[TestByteArrayReader setIndex case3],index is %d",reader->getIndex());
    }
    
    reader->setIndex(3);
    if(reader->getIndex() != 3) {
        TEST_FAIL("[TestByteArrayReader setIndex case4],index is %d",reader->getIndex());
    }
    
    value1 = reader->read<int>();
    value2 = 0x04|0x05<<8|0x06<<16|0x07<<24;
    if(value2 != value1) {
        TEST_FAIL("[TestByteArrayReader setIndex case5],v is %d,v2 is %d",value1,value2);
    }
    if(reader->getIndex() != 7) {
        TEST_FAIL("[TestByteArrayReader setIndex case6],index is %d",reader->getIndex());
    }
    
    try {
        reader->setIndex(32);
        TEST_FAIL("[TestByteArrayReader setIndex case7],index is %d",reader->getIndex());
    } catch(...) {}
    
    
    TEST_OK("[TestByteArrayReader setIndex case100]");
}
