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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Retry-After"),
                String::New(" Thu, 21 Oct 2021 07:28:00 GMT "));

    auto retryAfter = header->getRetryAfter();
    auto date = retryAfter->getDate()->toDateTime();
    if(date->year() != 2021) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case1]");
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case2]");
    }

    if(date->dayOfMonth() != 21) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case3]");
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case4]");
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case5]");
    }

    if(date->dayOfWeek() != st(Calendar)::Thursday) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case6],date->dayOfWeek() is %d",date->dayOfWeek());
    }
    break;
  }

  while(1) {
    HttpHeaderRetryAfter retryAfter = HttpHeaderRetryAfter::New();
    retryAfter->load(" 120 ");
    if(retryAfter->getDelayInterval() != 120) {
      TEST_FAIL("[HttpHeaderRetryAfter test SetToHeader case7]");
    }
    break;
  }

  TEST_OK("[HttpHeaderRetryAfter test SetToHeader case100]");
}
