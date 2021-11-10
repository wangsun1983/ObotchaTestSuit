#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlRequestHeaders.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER, Content-Type");
    if(!c->toString()->equals("X-PINGOTHER, Content-Type")) {
      printf("---[HttpHeaderAccessControlRequestHeaders test toString case1] [FAILED]--- \n");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER");
    if(!c->toString()->equals("X-PINGOTHER")) {
      printf("---[HttpHeaderAccessControlRequestHeaders test toString case3] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlRequestHeaders test toString case100] [OK]--- \n");

}
