#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->import("1");
    if(!dnt->toString()->equals("1")) {
      printf("---[HttpHeaderDnt test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->import("0");
    if(!dnt->toString()->equals("0")) {
      printf("---[HttpHeaderDnt test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderDnt test toString case100] [OK]--- \n");

}
