#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketKey.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    upgrade->import(" websocket ");
    if(!upgrade->get()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test Parse case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketKey test Parse case100]");
}
