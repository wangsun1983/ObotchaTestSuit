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


void testGetByteArray() {
    ByteArray data = ByteArray::New(5);
    ByteArrayWriter writer = ByteArrayWriter::New(data);
    writer->write<byte>(1);
    auto ret = writer->getByteArray();
    if(ret->size() != 1 || ret[0] != 0x1) {
        TEST_FAIL("[TestByteArrayWriter test getByteArray case1]");
    }
    
    TEST_OK("[TestByteArrayWriter test getByteArray case100]");
}
