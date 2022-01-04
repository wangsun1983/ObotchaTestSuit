#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint32.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestParseException() {
  Uint32 data = st(Uint32)::parseDecUint32("0x12");
  if(data != nullptr) {
    TEST_FAIL("Uint32 Parse Exception test1");
  }

  TEST_OK("Uint32 Parse Exception test100");
  return;
}
