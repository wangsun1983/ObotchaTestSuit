#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testToString() {
  String error = st(Error)::toString(InvalidParam);
  if(!error->equals("Invalid Param")) {
      TEST_FAIL("testErrorToString,invalid param fail,error is %s",error->toChars());
  }

  String error2 = st(Error)::toString(WaitTimeout);
  if(!error2->equals("Wait Timeout")) {
      TEST_FAIL("testErrorToString,Wait Time fail,error is %s",error2->toChars());
  }

  TEST_OK("testErrorToString case100");
}
