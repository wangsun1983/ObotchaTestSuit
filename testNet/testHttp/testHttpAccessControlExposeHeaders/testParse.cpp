#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlExposeHeaders.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlExposeHeaders c = createHttpHeaderAccessControlExposeHeaders();
    c->import("Content-Length, X-Kuma-Revision");
    auto list = c->get();
    String v0 = list->get(0);
    if(!v0->equals("Content-Length")) {
      printf("---[HttpHeaderAccessControlExposeHeaders test Parse case1] [FAILED]--- \n");
      break;
    }

    String v1 = list->get(1);
    if(!v1->equals("X-Kuma-Revision")) {
      printf("---[HttpHeaderAccessControlExposeHeaders test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlExposeHeaders test Parse case100] [OK]--- \n");

}
