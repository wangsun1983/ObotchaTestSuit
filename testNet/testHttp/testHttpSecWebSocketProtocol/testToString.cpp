#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketProtocol.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketProtocol c = createHttpHeaderSecWebSocketProtocol();
    c->import("  chat, superchat");
    if(!c->toString()->equals("chat, superchat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test toString case1],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketProtocol test toString case100]");

}
