#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("none");

    if(!ranges->toString()->equals("none")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test toString case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("bytes");

    if(!ranges->toString()->equals("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test toString case2]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccept test toString case100]");

}
