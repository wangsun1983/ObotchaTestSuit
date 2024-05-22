#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testEdgeDetection() {
    ByteArray data = ByteArray::New(4);
    ByteArrayReader reader = ByteArrayReader::New(data);
    
    try {
        reader->read<byte>();
    } catch(...) {
        TEST_FAIL("[TestByteArrayReader EdgeDetection case1]");
    }
    
    try {
        reader->read<uint32_t>();
        TEST_FAIL("[TestByteArrayReader EdgeDetection case2]");
    } catch(...) {
        
    }
    
    try {
        reader->read<byte>();
    } catch(...) {
        TEST_FAIL("[TestByteArrayReader EdgeDetection case3]");
    }
    
    try {
        reader->read<uint32_t>();
        TEST_FAIL("[TestByteArrayReader EdgeDetection case4]");
    } catch(...) {
        
    }
    
    try {
        reader->read<short int>();
    } catch(...) {
        TEST_FAIL("[TestByteArrayReader EdgeDetection case5]");
    }
    
    try {
        reader->read<byte>();
        TEST_FAIL("[TestByteArrayReader EdgeDetection case6]");
    } catch(...) {
        
    }

    TEST_OK("[TestByteArrayReader EdgeDetection case100]");
}
