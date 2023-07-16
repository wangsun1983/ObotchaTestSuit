#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "TextContent.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"

using namespace obotcha;

void testToString() {
//    _TextContent(const Integer &v);
    TextContent v1 = createTextContent(createInteger(2));
    if(!v1->get()->equals("2")) {
        TEST_FAIL("TextContent toString case1,v1 is [%s1111]",v1->get()->toChars());
    }

//    _TextContent(const Boolean &v);
    v1 = createTextContent(createBoolean(true));
    if(!v1->get()->equals("true")) {
        TEST_FAIL("TextContent toString case2,value is %s",v1->get()->toChars());
    }
    
    v1 = createTextContent(createBoolean(false));
    if(!v1->get()->equals("false")) {
        TEST_FAIL("TextContent toString case3");
    }
//    _TextContent(const Float &v);
//    v1 = createTextContent(createFloat(1.23));
//    if(!v1->get()->equals("1.23")) {
//        TEST_FAIL("TextContent toString case4,v1 is %s",v1->get()->toChars());
//    }
////    _TextContent(const Double &v);
//    v1 = createTextContent(createDouble(1.23));
//    if(!v1->get()->equals("1.23")) {
//        TEST_FAIL("TextContent toString case5");
//    }
//    _TextContent(const Long &v);
    v1 = createTextContent(createLong(100));
    if(!v1->get()->equals("100")) {
        TEST_FAIL("TextContent toString case6");
    }

//    _TextContent(const Uint8 &v);
    v1 = createTextContent(createUint8(10));
    if(!v1->get()->equals("10")) {
        TEST_FAIL("TextContent toString case7");
    }
//    _TextContent(const Uint16 &v);
    v1 = createTextContent(createUint16(15));
    if(!v1->get()->equals("15")) {
        TEST_FAIL("TextContent toString case8");
    }
//    _TextContent(const Uint32 &v);
    v1 = createTextContent(createUint32(120));
    if(!v1->get()->equals("120")) {
        TEST_FAIL("TextContent toString case9");
    }
//    _TextContent(const Uint64 &v);
    v1 = createTextContent(createUint64(160));
    if(!v1->get()->equals("160")) {
        TEST_FAIL("TextContent toString case10");
    }
//    _TextContent(const Byte &v);
    v1 = createTextContent(createByte(162));
    if(!v1->get()->equals("162")) {
        TEST_FAIL("TextContent toString case11");
    }
//    _TextContent(int v);
    v1 = createTextContent((int)162);
    if(!v1->get()->equals("162")) {
        TEST_FAIL("TextContent toString case12");
    }
//    _TextContent(bool v);
    v1 = createTextContent(true);
    if(!v1->get()->equals("true")) {
        TEST_FAIL("TextContent toString case13");
    }
    
    v1 = createTextContent(false);
    if(!v1->get()->equals("false")) {
        TEST_FAIL("TextContent toString case14");
    }
//    _TextContent(float v);
//    v1 = createTextContent((float)1.22);
//    if(!v1->get()->equals("1.22")) {
//        TEST_FAIL("TextContent toString case15");
//    }

//    _TextContent(double v);
//    v1 = createTextContent((double)1.26);
//    if(!v1->get()->equals("1.26")) {
//        TEST_FAIL("TextContent toString case16");
//    }

//    _TextContent(long v);
    v1 = createTextContent((long)166);
    if(!v1->get()->equals("166")) {
        TEST_FAIL("TextContent toString case17");
    }
//    _TextContent(char v);
    v1 = createTextContent((char)32);
    if(!v1->get()->equals("32")) {
        TEST_FAIL("TextContent toString case18");
    }
//    _TextContent(uint8_t);
    v1 = createTextContent((uint8_t)30);
    if(!v1->get()->equals("30")) {
        TEST_FAIL("TextContent toString case19");
    }
//    _TextContent(uint16_t);
    v1 = createTextContent((uint16_t)221);
    if(!v1->get()->equals("221")) {
        TEST_FAIL("TextContent toString case20");
    }
//    _TextContent(uint32_t);
    v1 = createTextContent((uint32_t)230);
    if(!v1->get()->equals("230")) {
        TEST_FAIL("TextContent toString case21");
    }
//    _TextContent(uint64_t);
    v1 = createTextContent((uint64_t)1230);
    if(!v1->get()->equals("1230")) {
        TEST_FAIL("TextContent toString case22");
    }
    TEST_OK("TextContent toString case100");
}   
