#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowMethods.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowMethods c = createHttpHeaderAccessControlAllowMethods();
    c->import("POST, GET, OPTIONS");
    if(!c->toString()->equals("POST, GET, OPTIONS")) {
      TEST_FAIL("---[HttpHeaderAccessControlAllowMethods test toString case1] ,str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("---[HttpHeaderAccessControlAllowMethods test toString case100]");

}
