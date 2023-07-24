#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRetryAfter.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->load(" Wed, 21 Oct 2015 07:28:00 GMT ");
    if(!retryAfter->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderRetryAfter test toString case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->load(" 120 ");
    if(!retryAfter->toString()->sameAs("120")) {
      TEST_FAIL("[HttpHeaderRetryAfter test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->load(" 120 ");
    header->setRetryAfter(retryAfter);
    
    auto retry = header->getRetryAfter();
    if(!retry->toString()->sameAs("120")) {
      TEST_FAIL("[HttpHeaderRetryAfter test toString case3]");
    }
    break;
  }

  TEST_OK("[HttpHeaderRetryAfter test toString case100]");
}
