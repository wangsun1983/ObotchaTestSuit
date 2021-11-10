#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowHeaders.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowHeaders c = createHttpHeaderAccessControlAllowHeaders();
    c->import("X-Custom-Header, Upgrade-Insecure-Requests");
    auto list = c->getHeaders();
    if(!list->get(0)->equals("X-Custom-Header")) {
      printf("---[HttpHeaderAccessControlAllowHeaders test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("Upgrade-Insecure-Requests")) {
      printf("---[HttpHeaderAccessControlAllowHeaders test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowHeaders c = createHttpHeaderAccessControlAllowHeaders();
    c->import("*");
    auto list = c->getHeaders();
    if(!list->get(0)->equals("*")) {
      printf("---[HttpHeaderAccessControlAllowHeaders test Parse case3] [FAILED]--- \n");
      break;
    }

    break;
  }
  printf("---[HttpAccessControlAllowCredentials test Parse case100] [OK]--- \n");

}
