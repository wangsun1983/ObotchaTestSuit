#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlRequestHeaders.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER, Content-Type");
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      printf("---[HttpHeaderAccessControlRequestHeaders test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("Content-Type")) {
      printf("---[HttpHeaderAccessControlRequestHeaders test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER");
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      printf("---[HttpHeaderAccessControlRequestHeaders test Parse case3] [FAILED]--- \n");
      break;
    }
    break;
  }
  printf("---[HttpHeaderAccessControlRequestHeaders test Parse case100] [OK]--- \n");

}
