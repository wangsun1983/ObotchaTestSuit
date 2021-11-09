#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("");

    if(!match->toString()->equals("")){
      printf("---[HttpHeaderReferer test toString case1] [FAILED]--- \n");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("https://developer.mozilla.org:1234");
    if(!match->toString()->equals("https://developer.mozilla.org:1234")){
      printf("---[HttpHeaderReferer test toString case2] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderReferer test toString case100] [OK]--- \n");
}
