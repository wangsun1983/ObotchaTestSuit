#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferer range = createHttpHeaderReferer();
    range->import("bytes=200-1000, 2000-6576, 19000-");
    if(!range->toString()->equals("bytes=200-1000, 2000-6576, 19000-")) {
      TEST_FAIL("[HttpHeaderReferer test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderReferer test toString case100]");

}
