#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAcceptCh acceptCh = createHttpHeaderAcceptCh();
    acceptCh->import("DPR, Viewport-Width, Width");
    if(!acceptCh->toString()->equals("DPR, Viewport-Width, Width")) {
      printf("---[HttpHeaderAcceptCh test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAcceptCh test toString case100] [OK]--- \n");

}
