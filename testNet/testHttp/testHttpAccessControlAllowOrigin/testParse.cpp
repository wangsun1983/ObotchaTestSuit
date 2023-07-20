#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowOrigin.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->load("https://developer.mozilla.org");
    if(!c->get()->equals("https://developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowOrigin c = createHttpHeaderAccessControlAllowOrigin();
    c->load("*");
    if(!c->get()->equals("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowOrigin test Parse case100]");

}
