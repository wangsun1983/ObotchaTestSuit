#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowCredentials.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->import("true");
    if(!c->isAllowed()) {
      printf("---[HttpHeaderAccessControlAllowCredentials test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->import("false");
    if(c->isAllowed()) {
      printf("---[HttpHeaderAccessControlAllowCredentials test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowCredentials test Parse case100] [OK]--- \n");

}
