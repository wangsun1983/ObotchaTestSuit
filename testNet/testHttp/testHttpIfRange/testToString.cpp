#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!range->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpHeaderIfRange test toString case1] [FAILED]--- str is %s\n",range->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->import("\"abcds\"");
    if(!range->toString()->equals("\"abcds\"")) {
      printf("---[HttpHeaderIfRange test toString case8] [FAILED]--- str is %s\n",range->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderIfRange test toString case100] [OK]--- \n");

}
