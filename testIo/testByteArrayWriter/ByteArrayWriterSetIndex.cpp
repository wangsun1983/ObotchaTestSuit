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
#include "TextLineReader.hpp"

using namespace obotcha;


void testSetIndex() {
    ByteArray writeData = createByteArray(2);
    writeData[0] = 0x1;
    writeData[1] = 0x2;
    ByteArray data = createByteArray(5);
    ByteArrayWriter writer = createByteArrayWriter(data);
    writer->setIndex(1);
    if(writer->getIndex() != 1) {
        TEST_FAIL("[TestByteArrayWriter test setIndex case1]");
    }
    
    writer->write(writeData);
    if(data[1] != 0x1 || data[2] != 0x2) {
        TEST_FAIL("[TestByteArrayWriter test setIndex case2]");
    }
    
    
    writer->setIndex(2);
    if(writer->getIndex() != 2) {
        TEST_FAIL("[TestByteArrayWriter test setIndex case3]");
    }
    
    writer->write(writeData);
    if(data[2] != 0x1 || data[3] != 0x2) {
        TEST_FAIL("[TestByteArrayWriter test setIndex case4]");
    }
    
    try {
        writer->setIndex(128);
        TEST_FAIL("[TestByteArrayWriter test setIndex case5]");
    } catch(...) {}
    
    TEST_OK("[TestByteArrayWriter test setIndex case100]");
}
