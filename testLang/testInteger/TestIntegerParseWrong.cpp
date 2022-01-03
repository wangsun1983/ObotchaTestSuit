#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIntegerParseWrong() {
  while(1) {
   Integer v1 = st(Integer)::parseDecInt("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test1");
    break;
   }

   v1 = st(Integer)::parseHexInt("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test2");
    break;
   }

   v1 = st(Integer)::parseOctInt("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test3");
    break;
   }

   v1 = st(Integer)::parseBinaryInt("111d");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test4");
    break;
   }

   TEST_OK("Integer testIntegerParseWrong test5");
   break;
  }
}
