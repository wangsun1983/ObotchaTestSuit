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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecWebSocketProtocol c = createHttpHeaderSecWebSocketProtocol();
    c->import(" chat, superchat");
    auto list = c->get();
    if(!list->get(0)->equals("chat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test Parse case1]");
      break;
    }

    if(!list->get(1)->equals("superchat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketProtocol test Parse case100]");

}
