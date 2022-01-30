#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVary.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderVary match = createHttpHeaderVary();
    match->import("no-referrer, User-Agent");
    if(!match->toString()->equals("no-referrer, User-Agent")) {
      TEST_FAIL("[HttpHeaderVary test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderVary test toString case100]");
}
