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
using namespace obotcha;


void testByteArrayWriterEdgeDetection() {
    ByteArray data = ByteArray::New(4);
    ByteArrayWriter writer = ByteArrayWriter::New(data);
    
    writer->write<byte>(1);
    try {
        printf("start write trace1 \n");
        writer->write<uint64_t>(100);
        TEST_FAIL("[TestByteArrayWriter edge detection case1]");
    } catch(...) {}
    
    try {
        writer->write<short int>(2);
    } catch(...) {
        TEST_FAIL("[TestByteArrayWriter edge detection case2]");
    }
    
    try {
        writer->write<short int>(2);
        TEST_FAIL("[TestByteArrayWriter edge detection case3]");
    } catch(...) {
        
    }
    writer->reset();
    
    ByteArray data1 = ByteArray::New(5);
    try {
        writer->write(data1);
        TEST_FAIL("[TestByteArrayWriter edge detection case4]");
    } catch(...) {}
    writer->reset();
    
    try {
        writer->write(data1,0,5);
        TEST_FAIL("[TestByteArrayWriter edge detection case5]");
    } catch(...) {}    
    writer->reset();
    
    try {
        writer->write(data1,0,4); 
    } catch(...) {
        TEST_FAIL("[TestByteArrayWriter edge detection case6]");
    }
    writer->reset();
    
    try {
        writer->write(data1,1,9); 
        TEST_FAIL("[TestByteArrayWriter edge detection case7]");
    } catch(...) {
        
    }
    
    TEST_OK("[TestByteArrayWriter edge detection case100]");
}
