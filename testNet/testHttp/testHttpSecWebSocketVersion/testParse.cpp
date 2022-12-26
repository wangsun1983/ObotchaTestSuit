#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderSecWebSocketVersion.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecWebSocketVersion c = createHttpHeaderSecWebSocketVersion();
    c->import(" 13");
    if(c->get() != 13) {
      TEST_FAIL("[HttpHeaderSecWebSocketVersion test Parse case1]");
      break;
    }
    
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketVersion test Parse case100]");

}
