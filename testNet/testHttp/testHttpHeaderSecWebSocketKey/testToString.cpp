#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketKey.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    upgrade->load(" websocket ");
    if(!upgrade->toString()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketKey test toString case100]");
}
