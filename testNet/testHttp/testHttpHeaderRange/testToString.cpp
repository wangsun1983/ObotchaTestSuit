#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRange.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderRange range = createHttpHeaderRange();
    range->import("bytes=200-1000, 2000-6576, 19000-");
    if(!range->toString()->equals("bytes=200-1000, 2000-6576, 19000-")) {
      TEST_FAIL("[HttpHeaderRange test toString case1],range is %s",range->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderRange test toString case100]");

}
