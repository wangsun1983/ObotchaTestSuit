#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"

using namespace obotcha;

void testProxyAuthenticateToString() {
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic");

    if(!proxyAuth->toString()->equals("Basic")) {
        printf("---[HttpHeaderProxyAuthenticate test toString case1] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic realm=\"Access to the internal site\"");

    if(!proxyAuth->toString()->equals("Basic realm=\"Access to the internal site\"")) {
        printf("---[HttpHeaderProxyAuthenticate test toString case2] [FAILED]--- auth is %s\n",proxyAuth->toString()->toChars());
        break;
    }

    break;
  }

  printf("---[HttpHeaderProxyAuthenticate test toString case100] [OK]--- \n");

}
