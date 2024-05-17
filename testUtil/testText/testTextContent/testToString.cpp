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
    TextContent v1 = TextContent::New(Integer::New(2));
    if(!v1->get()->sameAs("2")) {
        TEST_FAIL("TextContent toString case1,v1 is [%s1111]",v1->get()->toChars());
    }

//    _TextContent(const Boolean &v);
    v1 = TextContent::New(Boolean::New(true));
    if(!v1->get()->sameAs("true")) {
        TEST_FAIL("TextContent toString case2,value is %s",v1->get()->toChars());
    }
    
    v1 = TextContent::New(Boolean::New(false));
    if(!v1->get()->sameAs("false")) {
        TEST_FAIL("TextContent toString case3");
    }
//    _TextContent(const Float &v);
//    v1 = TextContent::New(Float::New(1.23));
//    if(!v1->get()->sameAs("1.23")) {
//        TEST_FAIL("TextContent toString case4,v1 is %s",v1->get()->toChars());
//    }
////    _TextContent(const Double &v);
//    v1 = TextContent::New(Double::New(1.23));
//    if(!v1->get()->sameAs("1.23")) {
//        TEST_FAIL("TextContent toString case5");
//    }
//    _TextContent(const Long &v);
    v1 = TextContent::New(Long::New(100));
    if(!v1->get()->sameAs("100")) {
        TEST_FAIL("TextContent toString case6");
    }

//    _TextContent(const Uint8 &v);
    v1 = TextContent::New(Uint8::New(10));
    if(!v1->get()->sameAs("10")) {
        TEST_FAIL("TextContent toString case7");
    }
//    _TextContent(const Uint16 &v);
    v1 = TextContent::New(Uint16::New(15));
    if(!v1->get()->sameAs("15")) {
        TEST_FAIL("TextContent toString case8");
    }
//    _TextContent(const Uint32 &v);
    v1 = TextContent::New(Uint32::New(120));
    if(!v1->get()->sameAs("120")) {
        TEST_FAIL("TextContent toString case9");
    }
//    _TextContent(const Uint64 &v);
    v1 = TextContent::New(Uint64::New(160));
    if(!v1->get()->sameAs("160")) {
        TEST_FAIL("TextContent toString case10");
    }
//    _TextContent(const Byte &v);
    v1 = TextContent::New(Byte::New(162));
    if(!v1->get()->sameAs("162")) {
        TEST_FAIL("TextContent toString case11");
    }
//    _TextContent(int v);
    v1 = TextContent::New((int)162);
    if(!v1->get()->sameAs("162")) {
        TEST_FAIL("TextContent toString case12");
    }
//    _TextContent(bool v);
    v1 = TextContent::New(true);
    if(!v1->get()->sameAs("true")) {
        TEST_FAIL("TextContent toString case13");
    }
    
    v1 = TextContent::New(false);
    if(!v1->get()->sameAs("false")) {
        TEST_FAIL("TextContent toString case14");
    }
//    _TextContent(float v);
//    v1 = TextContent::New((float)1.22);
//    if(!v1->get()->sameAs("1.22")) {
//        TEST_FAIL("TextContent toString case15");
//    }

//    _TextContent(double v);
//    v1 = TextContent::New((double)1.26);
//    if(!v1->get()->sameAs("1.26")) {
//        TEST_FAIL("TextContent toString case16");
//    }

//    _TextContent(long v);
    v1 = TextContent::New((long)166);
    if(!v1->get()->sameAs("166")) {
        TEST_FAIL("TextContent toString case17");
    }
//    _TextContent(char v);
    v1 = TextContent::New((char)32);
    if(!v1->get()->sameAs("32")) {
        TEST_FAIL("TextContent toString case18");
    }
//    _TextContent(uint8_t);
    v1 = TextContent::New((uint8_t)30);
    if(!v1->get()->sameAs("30")) {
        TEST_FAIL("TextContent toString case19");
    }
//    _TextContent(uint16_t);
    v1 = TextContent::New((uint16_t)221);
    if(!v1->get()->sameAs("221")) {
        TEST_FAIL("TextContent toString case20");
    }
//    _TextContent(uint32_t);
    v1 = TextContent::New((uint32_t)230);
    if(!v1->get()->sameAs("230")) {
        TEST_FAIL("TextContent toString case21");
    }
//    _TextContent(uint64_t);
    v1 = TextContent::New((uint64_t)1230);
    if(!v1->get()->sameAs("1230")) {
        TEST_FAIL("TextContent toString case22");
    }
    TEST_OK("TextContent toString case100");
}   
