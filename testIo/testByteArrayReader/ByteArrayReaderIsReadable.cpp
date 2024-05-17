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


void testIsReadable() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    ByteArray testData = ByteArray::New(array,8);
    ByteArrayReader reader = ByteArrayReader::New(testData);
    if(!reader->isReadable()) {
        TEST_FAIL("[TestByteArrayReader isReadable case1]");
    }
    
    reader->read<int>();
    if(!reader->isReadable()) {
        TEST_FAIL("[TestByteArrayReader isReadable case2]");
    }
    
    reader->read<int>();
    if(reader->isReadable()) {
        TEST_FAIL("[TestByteArrayReader isReadable case3]");
    }
    
    TEST_OK("[TestByteArrayReader isReadable case100]");
}
