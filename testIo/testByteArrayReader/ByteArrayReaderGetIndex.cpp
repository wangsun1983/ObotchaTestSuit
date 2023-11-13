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


void testGetIndex() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    ByteArray testData = createByteArray(array,8);
    ByteArrayReader reader = createByteArrayReader(testData);
    if(reader->getIndex() != 0) {
        TEST_FAIL("[TestByteArrayReader getIndex case1],index is %d",reader->getIndex());
    }
    
    reader->read<byte>();
    if(reader->getIndex() != 1) {
        TEST_FAIL("[TestByteArrayReader getIndex case2],index is %d",reader->getIndex());
    }
    
    reader->read<int>();
    if(reader->getIndex() != 5) {
        TEST_FAIL("[TestByteArrayReader getIndex case2],index is %d",reader->getIndex());
    }
    
    reader->read<byte>();
    if(reader->getIndex() != 6) {
        TEST_FAIL("[TestByteArrayReader getIndex case3],index is %d",reader->getIndex());
    }
    
    TEST_OK("[TestByteArrayReader Read Array case100]");
}
