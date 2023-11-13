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


void testWriteOverFlow() {
    ByteArray data = createByteArray(5);
    ByteArrayWriter writer = createByteArrayWriter(data);
    int ret = writer->write<long>(56);
    writer->reset();
    if(ret != -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case1]");
    }
    
    ByteArray testdata1 = createByteArray(5);
    ByteArray testdata2 = createByteArray(7);
    ret = writer->write(testdata1,0,5);
    writer->reset();
    if(ret == -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case2]");
    }
    
    ret = writer->write(testdata2,1,6);
    writer->reset();
    if(ret != -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case3]");
    }
    
    ret = writer->write(testdata2->toValue(),6);
    writer->reset();
    if(ret != -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case4]");
    }
    
    const char*p = "hello,world.haha";
    ret = writer->write(p,5);    
    if(ret == -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case6]");
    }
    writer->reset();
    if(data[0] != 'h' || data[1] != 'e' || data[2] != 'l'
        ||data[3] != 'l' || data[4] != 'o') {
        TEST_FAIL("[TestByteArrayWriter test overflow case7],[0] is %c,[1] is %c,[2] is %c,[3] is %c,[4] is %c",
            data[0],data[1],data[2],data[3],data[4]);
    }
    
    ret = writer->write(p,6);
    writer->reset();
    if(ret != -1) {
        TEST_FAIL("[TestByteArrayWriter test overflow case8]");
    }
    
    TEST_OK("[TestByteArrayWriter test overflow case100]");
}
