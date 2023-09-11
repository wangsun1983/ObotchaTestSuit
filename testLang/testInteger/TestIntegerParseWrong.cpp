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
#include "String.hpp"

using namespace obotcha;

void testIntegerParseWrong() {
  while(1) {
   Integer v1 = st(Integer)::ParseDecString("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test1");
    break;
   }

   v1 = st(Integer)::ParseHexString("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test2");
    break;
   }

   v1 = st(Integer)::ParseOctString("xd");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test3");
    break;
   }

   v1 = st(Integer)::ParseBinaryString("111d");
   if(v1 != nullptr) {
    TEST_FAIL("Integer testIntegerParseWrong test4");
    break;
   }

   TEST_OK("Integer testIntegerParseWrong test5");
   break;
  }
}
