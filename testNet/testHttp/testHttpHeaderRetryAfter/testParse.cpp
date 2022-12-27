#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRetryAfter.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->import(" Thu, 21 Oct 2021 07:28:00 GMT ");
    auto date = retryAfter->getDate()->toDateTime();
    if(date->year() != 2021) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case1]");
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case2]");
    }

    if(date->dayOfMonth() != 21) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case3]");
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case4]");
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case5]");
    }

    if(date->dayOfWeek() != st(Calendar)::Thursday) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case6],date->dayOfWeek() is %d",date->dayOfWeek());
    }
    break;
  }

  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter();
    retryAfter->import(" 120 ");
    if(retryAfter->getDelayInterval() != 120) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case7]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderRetryAfter retryAfter = createHttpHeaderRetryAfter(" Thu, 21 Oct 2021 07:28:00 GMT ");
    auto date = retryAfter->getDate()->toDateTime();
    if(date->year() != 2021) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case8]");
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case9]");
    }

    if(date->dayOfMonth() != 21) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case10]");
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case11]");
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case12]");
    }

    if(date->dayOfWeek() != st(Calendar)::Thursday) {
      TEST_FAIL("[HttpHeaderRetryAfter test Parse case13],date->dayOfWeek() is %d",date->dayOfWeek());
    }
    break;
  }

  TEST_OK("[HttpHeaderRetryAfter test Parse case100]");
}
