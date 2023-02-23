#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowOrigin.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("https://developer.mozilla.org");
    if(!c->toString()->equals("https://developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->import("*");
    if(!c->toString()->equals("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->set("*");
    if(!c->toString()->equals("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowOrigin test toString case100]");

}
