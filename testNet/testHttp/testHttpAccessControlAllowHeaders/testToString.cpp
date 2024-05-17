#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowHeaders.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowHeaders c = HttpHeaderAccessControlAllowHeaders::New();
    c->load("X-Custom-Header, Upgrade-Insecure-Requests");
    if(!c->toString()->sameAs("X-Custom-Header, Upgrade-Insecure-Requests")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test toString case1] [FAILED] ,str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowHeaders c = HttpHeaderAccessControlAllowHeaders::New();
    c->load("*");
    if(!c->toString()->sameAs("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowCredentials test toString case100]");

}
