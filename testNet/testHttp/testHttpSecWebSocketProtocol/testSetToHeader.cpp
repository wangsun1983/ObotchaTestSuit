#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderSecWebSocketProtocol.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Sec-WebSocket-Protocol"),
                createString(" chat, superchat"));
    auto c = header->getWebSocketProtocol();
    auto list = c->get();
    if(!list->get(0)->sameAs("chat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test setToHeader case1]");
      break;
    }

    if(!list->get(1)->sameAs("superchat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketProtocol test setToHeader case100]");

}
