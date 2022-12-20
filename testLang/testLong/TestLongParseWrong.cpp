#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Long.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLongParseWrong() {
  while(1) {
   Long v1 = st(Long)::parseDecLong("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Long testLongParseWrong test1,v is %ld",v1->toValue());
    break;
   }

   v1 = st(Long)::parseHexLong("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Long testLongParseWrong test2");
    break;
   }

   v1 = st(Long)::parseOctLong("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Long testLongParseWrong test3");
    break;
   }

   v1 = st(Long)::parseBinaryLong("111d");
   if(v1 != nullptr) {
    TEST_FAIL("Long testLongParseWrong test4,v is %x",v1->toValue());
    break;
   }

   TEST_OK("Long testLongParseWrong test5");
   break;
  }
}
