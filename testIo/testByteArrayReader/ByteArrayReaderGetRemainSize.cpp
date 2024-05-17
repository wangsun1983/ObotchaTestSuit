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


void testGetRemainSize() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    ByteArray testData = ByteArray::New(array,8);
    ByteArrayReader reader = ByteArrayReader::New(testData);
    if(reader->getRemainSize() != 8) {
        TEST_FAIL("[TestByteArrayReader getRemainSize case1],remain size is %d",reader->getRemainSize());
    }
    
    reader->read<byte>();
    if(reader->getRemainSize() != 7) {
        TEST_FAIL("[TestByteArrayReader getRemainSize case2],remain size is %d",reader->getRemainSize());
    }
    
    reader->read<int>();
    if(reader->getRemainSize() != 3) {
        TEST_FAIL("[TestByteArrayReader getRemainSize case3],remain size is %d",reader->getRemainSize());
    }
    
    reader->read<byte>();
    if(reader->getRemainSize() != 2) {
        TEST_FAIL("[TestByteArrayReader getRemainSize case3],index is %d",reader->getRemainSize());
    }
    reader->read<byte>();
    reader->read<byte>();
    if(reader->getRemainSize() != 0) {
        TEST_FAIL("[TestByteArrayReader getRemainSize case3],index is %d",reader->getRemainSize());
    }
    
    TEST_OK("[TestByteArrayReader getRemainSize case100]");
}
