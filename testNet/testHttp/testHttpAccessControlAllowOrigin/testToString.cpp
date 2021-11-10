#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowOrigin.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("https://developer.mozilla.org");
    if(!c->toString()->equals("https://developer.mozilla.org")) {
      printf("---[HttpHeaderAccessControlAllowOrigin test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("*");
    if(!c->toString()->equals("*")) {
      printf("---[HttpHeaderAccessControlAllowOrigin test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowOrigin test toString case100] [OK]--- \n");

}
