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


void testSkipBy() {
    ByteArray data = ByteArray::New(3);
    ByteArrayWriter writer = ByteArrayWriter::New(data);
    int ret = writer->skipBy(1);
    if(ret != 0) {
        TEST_FAIL("[TestByteArrayWriter test skipBy case1]");
    }
    
    ret = writer->skipBy(1);
    if(ret != 0) {
        TEST_FAIL("[TestByteArrayWriter test skipBy case2]");
    }
    
    ret = writer->skipBy(1);
    if(ret != 0) {
        TEST_FAIL("[TestByteArrayWriter test skipBy case3]");
    }
    
    try {
        writer->skipBy(1);
        TEST_FAIL("[TestByteArrayWriter test skipBy case4]");
    } catch(...){}
    
    writer->reset();
    ret = writer->skipBy(2);
    if(ret != 0) {
        TEST_FAIL("[TestByteArrayWriter test skipBy case5]");
    }
    
    try {
        writer->skipBy(2);
        TEST_FAIL("[TestByteArrayWriter test skipBy case6]");
    } catch(...) {}
    
    TEST_OK("[TestByteArrayWriter test skipBy case100]");
}
