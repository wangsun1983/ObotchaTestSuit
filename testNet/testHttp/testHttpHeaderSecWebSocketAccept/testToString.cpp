#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketAccept.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketAccept upgrade = createHttpHeaderSecWebSocketAccept();
    upgrade->load(" s3pPLMBiTxaQ9kYGzzhZRbK+xOo= ");
    if(!upgrade->toString()->sameAs("s3pPLMBiTxaQ9kYGzzhZRbK+xOo=")) {
      TEST_FAIL("[HttpHeaderSecWebSocketAccept test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketAccept test toString case100]");
}
