#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowCredentials.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->load("true");
    if(!c->toString()->sameAs("true")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->load("false");
    if(!c->toString()->sameAs("false")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowCredentials test toString case100]");

}
