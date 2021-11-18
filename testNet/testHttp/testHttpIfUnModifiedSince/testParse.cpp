#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfUnmodifiedSince.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testPatchParse() {
  while(1) {
    HttpHeaderIfUnmodifiedSince modifiedSince = createHttpHeaderIfUnmodifiedSince();
    modifiedSince->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    auto date = modifiedSince->get()->toDateTime();
    if(date->year() != 2015) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case1] [FAILED]--- \n");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case2] [FAILED]--- \n");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case3] [FAILED]--- \n");
      break;
    }

    if(date->hour() != 7) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case4] [FAILED]--- \n");
      break;
    }

    if(date->minute() != 28) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case5] [FAILED]--- \n");
      break;
    }

    if(date->second() != 0) {
      printf("---[HttpHeaderIfUnmodifiedSince test Parse case6] [FAILED]--- \n");
      break;
    }
    break;
  }
  printf("---[HttpHeaderIfUnmodifiedSince test Parse case100] [OK]--- \n");

}
