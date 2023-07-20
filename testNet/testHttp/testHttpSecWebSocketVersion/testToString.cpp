#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketVersion.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketVersion c = createHttpHeaderSecWebSocketVersion();
    c->load(" 13");
    if(!c->toString()->equals("13")) {
      TEST_FAIL("[HttpHeaderSecWebSocketVersion test toString case1],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketVersion test toString case100]");

}
