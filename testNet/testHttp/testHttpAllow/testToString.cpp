#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAllow.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAllow c = createHttpHeaderAllow();
    c->import("POST, GET, OPTIONS");
    if(!c->toString()->equals("POST, GET, OPTIONS")) {
      TEST_FAIL("[HttpHeaderAllow test toString case1],str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAllow test toString case100]");

}
