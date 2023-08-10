#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderSecWebSocketExtensions.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Sec-WebSocket-Extensions"),
                createString(" permessage-deflate, client_max_window_bits"));
    auto c = header->getWebSocketExtensions();
    auto list = c->get();
    if(!list->get(0)->sameAs("permessage-deflate")) {
      TEST_FAIL("[HttpHeaderSecWebSocketExtensions test setToHeader case1]");
      break;
    }

    if(!list->get(1)->sameAs("client_max_window_bits")) {
      TEST_FAIL("[HttpHeaderSecWebSocketExtensions test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketExtensions test setToHeader case100]");

}
