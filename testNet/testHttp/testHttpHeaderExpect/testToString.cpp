#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderExpect expect = createHttpHeaderExpect();
  expect->import("100-continue");
  if(!expect->toString()->equals("100-continue")) {
    TEST_FAIL("[HttpHeaderExpect test toString case1]");
  }

  TEST_OK("[HttpHeaderExpect test toString case100]");

}
