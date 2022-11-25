#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestParseException() {
  Uint16 data = st(Uint16)::parseDecString("0x12");
  if(data != nullptr) {
    TEST_FAIL("Uint16 Parse Exception test1");
  }

  TEST_OK("Uint16 Parse Exception test100");
  return;
}
