#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(range->getDate() == nullptr) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case1]");
      break;
    }

    auto date = range->getDate()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case2]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case3]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case4]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case5]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case6]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case7]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->load("\"abcds\"");
    if(range->getTag()== nullptr || !range->getTag()->sameAs("abcds")) {
      TEST_FAIL("[HttpHeaderIfRange test Parse case8]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderIfRange test Parse case100]");

}
