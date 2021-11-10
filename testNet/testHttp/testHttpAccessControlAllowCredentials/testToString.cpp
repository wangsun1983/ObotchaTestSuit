#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowCredentials.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->import("true");
    if(!c->toString()->equals("true")) {
      printf("---[HttpHeaderAccessControlAllowCredentials test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->import("false");
    if(!c->toString()->equals("false")) {
      printf("---[HttpHeaderAccessControlAllowCredentials test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowCredentials test Parse case100] [OK]--- \n");



  printf("---[HttpHeaderAccessControlAllowCredentials test toString case100] [OK]--- \n");

}
