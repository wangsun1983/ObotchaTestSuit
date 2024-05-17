#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketExtensions.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketExtensions c = HttpHeaderSecWebSocketExtensions::New();
    c->load(" permessage-deflate, client_max_window_bits");
    if(!c->toString()->sameAs("permessage-deflate, client_max_window_bits")) {
      TEST_FAIL("[HttpHeaderSecWebSocketExtensions test toString case1],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketExtensions test toString case100]");

}
