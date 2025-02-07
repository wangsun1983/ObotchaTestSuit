#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"
#include "String.hpp"

using namespace obotcha;

void testParse() {
   auto v = st(Uint8)::Parse(String::New("12"));
   if(v->toValue() != 12) {
     TEST_FAIL("Uint8 parse case1");
   }

   auto v2 = st(Uint8)::Parse(String::New("300"));
   if(v2 != nullptr) {
     TEST_FAIL("Uint8 parse case2");
   }

   TEST_OK("Uint8 parse case100");
   return;
}
