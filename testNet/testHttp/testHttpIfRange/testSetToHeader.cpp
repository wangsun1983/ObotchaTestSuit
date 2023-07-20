#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("If-Range"),createString(" Wed, 21 Oct 2015 07:28:00 GMT"));
    auto range = header->getIfRange();
    range->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(range->getDate() == nullptr) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case1]");
      break;
    }

    auto date = range->getDate()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case2]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case3]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case4]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case5]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case6]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case7]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->load("\"abcds\"");
    HttpHeader header = createHttpHeader();
    header->setIfRange(range);
    auto rr = header->getIfRange();
    if(rr->getTag()== nullptr || !rr->getTag()->equals("abcds")) {
      TEST_FAIL("[HttpHeaderIfRange test setToHeader case8]");
    }
    break;
  }

  TEST_OK("[HttpHeaderIfRange test setToHeader case100]");

}
