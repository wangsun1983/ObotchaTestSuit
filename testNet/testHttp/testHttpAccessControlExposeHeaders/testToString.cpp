#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlExposeHeaders.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlExposeHeaders c = createHttpHeaderAccessControlExposeHeaders();
    c->import("Content-Length, X-Kuma-Revision");
    if(c->toString()->equals("Content-Length, X-Kuma-Revision")) {
      printf("---[HttpHeaderAccessControlAllowOrigin test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowOrigin test toString case100] [OK]--- \n");

}
