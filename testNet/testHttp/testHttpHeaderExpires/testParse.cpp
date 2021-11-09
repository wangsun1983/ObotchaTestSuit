#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpires.hpp"
#include "Math.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderExpires headerDate = createHttpHeaderExpires();
    headerDate->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    auto date = headerDate->get()->toDateTime();
    if(date->year() != 2015) {
      printf("---[HttpHeaderExpires test Parse case1] [FAILED]--- \n");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      printf("---[HttpHeaderExpires test Parse case2] [FAILED]--- \n");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      printf("---[HttpHeaderExpires test Parse case3] [FAILED]--- \n");
      break;
    }

    if(date->hour() != 7) {
      printf("---[HttpHeaderExpires test Parse case4] [FAILED]--- \n");
      break;
    }

    if(date->minute() != 28) {
      printf("---[HttpHeaderExpires test Parse case5] [FAILED]--- \n");
      break;
    }

    if(date->second() != 0) {
      printf("---[HttpHeaderExpires test Parse case6] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderExpires test Parse case100] [OK]--- \n");

}
