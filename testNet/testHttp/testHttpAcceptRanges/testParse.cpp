#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("bytes");

    if(!ranges->get()->equals("bytes")) {
        printf("---[HttpHeaderAcceptRanges test Parse case1] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    ranges->import("none");

    if(!ranges->get()->equals("none")) {
        printf("---[HttpHeaderAcceptRanges test Parse case2] [FAILED]--- \n");
        break;
    }
    break;
  }

  printf("---[HttpHeaderAcceptRanges test Parse case100] [OK]--- \n");

}
