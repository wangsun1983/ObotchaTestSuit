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

using namespace obotcha;

void TestParseException() {
  Uint8 data = st(Uint8)::parseDecString("0x12");
  if(data != nullptr) {
    TEST_FAIL("Uint8 Parse Exception test1");
  }

  TEST_OK("Uint8 Parse Exception test100");
}
