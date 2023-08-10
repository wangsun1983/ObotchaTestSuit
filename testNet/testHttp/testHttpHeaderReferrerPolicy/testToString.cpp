#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferrerPolicy.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferrerPolicy match = createHttpHeaderReferrerPolicy();
    match->load("no-referrer, strict-origin-when-cross-origin");
    if(!match->toString()->sameAs("no-referrer, strict-origin-when-cross-origin")) {
      TEST_FAIL("[HttpHeaderReferrerPolicy test toString case1] ");
    }
    break;
  }

  TEST_OK("[HttpHeaderReferrerPolicy test toString case100]");
}
