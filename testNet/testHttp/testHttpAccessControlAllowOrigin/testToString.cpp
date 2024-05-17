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
    HttpHeaderAccessControlAllowOrigin c = HttpHeaderAccessControlAllowOrigin::New();
    c->load("https://developer.mozilla.org");
    if(!c->toString()->sameAs("https://developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowOrigin c = HttpHeaderAccessControlAllowOrigin::New();
    c->load("*");
    if(!c->toString()->sameAs("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = HttpHeaderAccessControlAllowOrigin::New();
    c->set("*");
    if(!c->toString()->sameAs("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowOrigin test toString case100]");

}
