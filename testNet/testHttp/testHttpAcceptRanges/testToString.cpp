#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("none");

    if(!ranges->toString()->equals("none")) {
        printf("---[HttpHeaderAcceptRanges test toString case2] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("bytes");

    if(!ranges->toString()->equals("bytes")) {
        printf("---[HttpHeaderAcceptRanges test toString case2] [FAILED]--- \n");
        break;
    }
    break;
  }

  printf("---[HttpHeaderAccept test toString case100] [OK]--- \n");

}
