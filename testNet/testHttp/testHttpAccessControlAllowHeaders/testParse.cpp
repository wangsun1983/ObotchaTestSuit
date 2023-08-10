#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowHeaders.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowHeaders c = createHttpHeaderAccessControlAllowHeaders();
    c->load("X-Custom-Header, Upgrade-Insecure-Requests");
    auto list = c->get();
    if(!list->get(0)->sameAs("X-Custom-Header")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowHeaders test Parse case1]");
      break;
    }

    if(!list->get(1)->sameAs("Upgrade-Insecure-Requests")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowHeaders test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowHeaders c = createHttpHeaderAccessControlAllowHeaders();
    c->load("*");
    auto list = c->get();
    if(!list->get(0)->sameAs("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowHeaders test Parse case3]");
      break;
    }

    break;
  }
  TEST_OK("[HttpAccessControlAllowCredentials test Parse case100]");

}
