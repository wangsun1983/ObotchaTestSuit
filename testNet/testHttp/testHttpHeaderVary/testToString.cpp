#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVary.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderVary match = createHttpHeaderVary();
    match->import("no-referrer, User-Agent");
    if(!match->toString()->equals("no-referrer, User-Agent")) {
      printf("---[HttpHeaderVary test toString case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderVary test toString case100] [OK]--- \n");
}
