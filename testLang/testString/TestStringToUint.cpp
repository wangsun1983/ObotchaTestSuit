#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"
#include "IllegalArgumentException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestStringToUint() {
    
    //uint8
    while(1) {
        Uint8 v = String::New("100")->toUint8();
        if(v == nullptr || v->toValue() != 100) {
            TEST_FAIL("String toUint8 test1,value is %d",v->toValue());
        }
        
        v = String::New("500")->toUint8();
        if(v != nullptr) {
            TEST_FAIL("String toUint8 test2,v is %d ",v->toValue());
        }
        break;
    }
    
    //uint16
    while(1) {
        Uint16 v = String::New("100")->toUint16();
        if(v == nullptr || v->toValue() != 100) {
            TEST_FAIL("String toUint16 test1,v is %d",v->toValue());
        }
        
        v = String::New("1000000000000")->toUint16();
        if(v != nullptr) {
            TEST_FAIL("String toUint16 test2,v is %d",v->toValue());
        }
        break;
    }
    
    //uint32
    while(1) {
        Uint32 v = String::New("99999")->toUint32();
        if(v == nullptr || v->toValue() != 99999) {
            TEST_FAIL("String toUint32 test1");
        }
        
        v = String::New("5294967295")->toUint32();
        if(v != nullptr) {
            TEST_FAIL("String toUint32 test2");
        }
        break;
    }
    
    //uint64
    while(1) {
        Uint64 v = String::New("1003333")->toUint64();
        if(v == nullptr || v->toValue() != 1003333) {
            TEST_FAIL("String toUint64 test1");
        }
        
        v = String::New("888888888503599627370495")->toUint64();
        if(v != nullptr) {
            TEST_FAIL("String toUint64 test2");
        }
        break;
    }
    TEST_OK("String update test100");
}
