#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlMaxAge.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlMaxAge c = createHttpHeaderAccessControlMaxAge();
    c->load("600");
    if(!c->toString()->equals("600")) {
      TEST_FAIL("[HttpHeaderAccessControlMaxAge test toString case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlMaxAge test toString case100]");

}
