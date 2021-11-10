#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowOrigin.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("https://developer.mozilla.org");
    if(!c->get()->equals("https://developer.mozilla.org")) {
      printf("---[HttpHeaderAccessControlAllowOrigin test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("*");
    if(!c->get()->equals("*")) {
      printf("---[HttpHeaderAccessControlAllowOrigin test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowOrigin test Parse case100] [OK]--- \n");

}
