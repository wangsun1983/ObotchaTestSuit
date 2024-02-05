#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBytRingArrayEdgeDetection() {
    while(1) {
        ByteRingArray array = createByteRingArray(5);
        ByteArray data1 = createByteArray(3);
        
        try {
            array->push(data1,1,3);
            TEST_FAIL("[ByteRingArray Test Edge detection case1");
        } catch(...) {}
        
        break;
    }
    
    while(1) {
        ByteRingArray array = createByteRingArray(5);
        array->setStartIndex(2);
        array->setSize(0);
        
        auto data1 = createByteArray(5);
        try {
            array->push(data1);
        } catch(...) {
            TEST_FAIL("[ByteRingArray Test Edge detection case2");
        }
        break;
    }
    
    while(1) {
        ByteRingArray array = createByteRingArray(5);
        array->setStartIndex(2);
        array->setSize(1);
        
        auto data1 = createByteArray(5);
        try {
            array->push(data1);
            TEST_FAIL("[ByteRingArray Test Edge detection case3");
        } catch(...) {
        }
        
        data1 = createByteArray(4);
        try {
            array->push(data1);
        } catch(...) {
            TEST_FAIL("[ByteRingArray Test Edge detection case4");
        }
        array->setSize(1);
        
        data1 = createByteArray(3);
        try {
            array->push(data1);
        } catch(...) {
            TEST_FAIL("[ByteRingArray Test Edge detection case5");
        }
        array->setSize(1);
        
        data1 = createByteArray(2);
        try {
            array->push(data1);
        } catch(...) {
            TEST_FAIL("[ByteRingArray Test Edge detection case6");
        }
        array->setSize(1);
        
        data1 = createByteArray(1);
        try {
            array->push(data1);
        } catch(...) {
            TEST_FAIL("[ByteRingArray Test Edge detection case7");
        }
        break;
    }
    
    TEST_OK("[ByteRingArray Test Edge detection case100");
}
