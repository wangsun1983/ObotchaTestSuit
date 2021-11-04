#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpIfRange.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpIfRange range = createHttpIfRange();
    range->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!range->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpIfRange test toString case1] [FAILED]--- str is %s\n",range->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpIfRange range = createHttpIfRange();
    range->import("\"abcds\"");
    if(!range->toString()->equals("\"abcds\"")) {
      printf("---[HttpIfRange test toString case8] [FAILED]--- str is %s\n",range->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpIfRange test toString case100] [OK]--- \n");

}
