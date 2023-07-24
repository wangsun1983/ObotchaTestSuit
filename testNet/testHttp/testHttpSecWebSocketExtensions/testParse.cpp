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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecWebSocketExtensions c = createHttpHeaderSecWebSocketExtensions();
    c->load(" permessage-deflate, client_max_window_bits");
    auto list = c->get();
    if(!list->get(0)->sameAs("permessage-deflate")) {
      TEST_FAIL("[HttpHeaderSecWebSocketExtensions test Parse case1]");
      break;
    }

    if(!list->get(1)->sameAs("client_max_window_bits")) {
      TEST_FAIL("[HttpHeaderSecWebSocketExtensions test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketExtensions test Parse case100]");

}
