#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferrerPolicy.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferrerPolicy match = createHttpHeaderReferrerPolicy();
    match->import("no-referrer, strict-origin-when-cross-origin");
    if(!match->toString()->equals("no-referrer, strict-origin-when-cross-origin")) {
      printf("---[HttpHeaderReferrerPolicy test toString case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderReferrerPolicy test toString case100] [OK]--- \n");
}
