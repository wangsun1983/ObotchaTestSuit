#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("bytes");

    if(!ranges->get()->equals("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("none");

    if(!ranges->get()->equals("none")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case2]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptRanges test Parse case100]");

}
