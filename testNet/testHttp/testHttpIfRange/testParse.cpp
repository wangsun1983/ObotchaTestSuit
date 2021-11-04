#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpIfRange.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpIfRange range = createHttpIfRange();
    range->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(range->getDate() == nullptr) {
      printf("---[HttpIfRange test Parse case1] [FAILED]--- \n");
      break;
    }

    auto date = range->getDate()->toDateTime();
    if(date->year() != 2015) {
      printf("---[HttpIfRange test Parse case2] [FAILED]--- \n");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      printf("---[HttpIfRange test Parse case3] [FAILED]--- \n");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      printf("---[HttpIfRange test Parse case4] [FAILED]--- \n");
      break;
    }

    if(date->hour() != 7) {
      printf("---[HttpIfRange test Parse case5] [FAILED]--- \n");
      break;
    }

    if(date->minute() != 28) {
      printf("---[HttpIfRange test Parse case6] [FAILED]--- \n");
      break;
    }

    if(date->second() != 0) {
      printf("---[HttpIfRange test Parse case7] [FAILED]--- \n");
      break;
    }

    break;
  }

  while(1) {
    HttpIfRange range = createHttpIfRange();
    range->import("\"abcds\"");
    if(range->getTag()== nullptr || !range->getTag()->equals("abcds")) {
      printf("---[HttpIfRange test Parse case8] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpIfRange test Parse case100] [OK]--- \n");

}
