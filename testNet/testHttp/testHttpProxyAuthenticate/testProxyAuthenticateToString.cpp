#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testProxyAuthenticateToString() {
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic");

    if(!proxyAuth->toString()->equals("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test toString case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic realm=\"Access to the internal site\"");

    if(!proxyAuth->toString()->equals("Basic realm=\"Access to the internal site\"")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test toString case2] auth is %s",proxyAuth->toString()->toChars());
        break;
    }

    break;
  }

  TEST_OK("[HttpHeaderProxyAuthenticate test toString case100]");

}
