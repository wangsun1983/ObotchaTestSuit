#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"
#include "Math.hpp"

using namespace obotcha;

void testProxyAuthenticateParse() {
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic");

    if(!proxyAuth->type->equals("Basic")) {
        printf("---[HttpHeaderProxyAuthenticate test Parse case1] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->import("Basic realm=\"Access to the internal site\"");

    if(!proxyAuth->type->equals("Basic")) {
        printf("---[HttpHeaderProxyAuthenticate test Parse case2] [FAILED]--- \n");
        break;
    }

    if(!proxyAuth->realm->equals("Access to the internal site")) {
        printf("---[HttpHeaderProxyAuthenticate test Parse case3] [FAILED]--- \n");
        break;
    }
    break;
  }

  printf("---[HttpHeaderProxyAuthenticate test Parse case100] [OK]--- \n");

}
