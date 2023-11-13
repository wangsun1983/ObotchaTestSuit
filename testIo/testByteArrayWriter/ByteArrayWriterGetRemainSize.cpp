#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "ByteArrayWriter.hpp"
#include <string.h>
#include "TestLog.hpp"
#include "File.hpp"
#include "BufferedReader.hpp"

using namespace obotcha;


void testGetRemainSize() {
    ByteArray data = createByteArray(5);
    ByteArrayWriter writer = createByteArrayWriter(data);
    writer->write<byte>(1);
    if(writer->getRemainSize() != 4) {
        TEST_FAIL("[TestByteArrayWriter test getRemainSize case1]");
    }
    
    writer->write<byte>(1);
    if(writer->getRemainSize() != 3) {
        TEST_FAIL("[TestByteArrayWriter test getRemainSize case2]");
    }
    
    writer->write<byte>(1);
    if(writer->getRemainSize() != 2) {
        TEST_FAIL("[TestByteArrayWriter test getRemainSize case3]");
    }
    
    writer->write<byte>(1);
    if(writer->getRemainSize() != 1) {
        TEST_FAIL("[TestByteArrayWriter test getRemainSize case4]");
    }
    
    writer->write<byte>(1);
    if(writer->getRemainSize() != 0) {
        TEST_FAIL("[TestByteArrayWriter test getRemainSize case5]");
    }
    
    TEST_OK("[TestByteArrayWriter test getRemainSize case100]");
}
