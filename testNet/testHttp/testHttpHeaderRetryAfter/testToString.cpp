#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRetryAfter.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->import(" Wed, 21 Oct 2015 07:28:00 GMT ");
    if(!retryAfter->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderRetryAfter test toString case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->import(" 120 ");
    if(!retryAfter->toString()->equals("120")) {
      TEST_FAIL("[HttpHeaderRetryAfter test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderRetryAfter test toString case100]");
}
