#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint64.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void TestParseException() {
  Uint64 data = st(Uint64)::parseDecString("0x12");
  if(data != nullptr) {
    TEST_FAIL("Uint64 Parse Exception test1");
  }

  TEST_OK("Uint64 Parse Exception test100");
  return;
}
