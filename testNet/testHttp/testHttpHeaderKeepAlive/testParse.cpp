#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderKeepAlive.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->import("timeout=5, max=1000");
    if(keepAlive->getTimeout() != 5 || keepAlive->getMax() != 1000) {
      TEST_FAIL("[HttpHeaderKeepAlive test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->import("1000");
    if(keepAlive->getTimeout() != 1000) {
      TEST_FAIL("[HttpHeaderKeepAlive test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->import("timeout=5");
    if(keepAlive->getTimeout() != 5) {
      TEST_FAIL("[HttpHeaderKeepAlive test Parse case3]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->import("Max=5");
    if(keepAlive->getMax() != 5) {
      TEST_FAIL("[HttpHeaderKeepAlive test Parse case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderKeepAlive test Parse case100]");
}
