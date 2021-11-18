#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(range->getDate() == nullptr) {
      printf("---[HttpHeaderIfRange test Parse case1] [FAILED]--- \n");
      break;
    }

    auto date = range->getDate()->toDateTime();
    if(date->year() != 2015) {
      printf("---[HttpHeaderIfRange test Parse case2] [FAILED]--- \n");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      printf("---[HttpHeaderIfRange test Parse case3] [FAILED]--- \n");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      printf("---[HttpHeaderIfRange test Parse case4] [FAILED]--- \n");
      break;
    }

    if(date->hour() != 7) {
      printf("---[HttpHeaderIfRange test Parse case5] [FAILED]--- \n");
      break;
    }

    if(date->minute() != 28) {
      printf("---[HttpHeaderIfRange test Parse case6] [FAILED]--- \n");
      break;
    }

    if(date->second() != 0) {
      printf("---[HttpHeaderIfRange test Parse case7] [FAILED]--- \n");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->import("\"abcds\"");
    if(range->getTag()== nullptr || !range->getTag()->equals("abcds")) {
      printf("---[HttpHeaderIfRange test Parse case8] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderIfRange test Parse case100] [OK]--- \n");

}
