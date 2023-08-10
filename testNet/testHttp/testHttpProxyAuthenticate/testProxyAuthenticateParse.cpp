#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testProxyAuthenticateParse() {
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->load("Basic");

    if(!proxyAuth->type->sameAs("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test Parse case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->load("Basic realm=\"Access to the internal site\"");

    if(!proxyAuth->type->sameAs("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test Parse case2]");
        break;
    }

    if(!proxyAuth->realm->sameAs("Access to the internal site")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test Parse case3]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderProxyAuthenticate test Parse case100]");

}
