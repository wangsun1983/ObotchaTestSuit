#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Proxy-Authenticate"),
                createString("Basic"));
                
    auto proxyAuth = header->getProxyAuthenticate();

    if(!proxyAuth->type->sameAs("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test setToHeader case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Proxy-Authenticate"),
                createString("Basic realm=\"Access to the internal site\""));
    auto proxyAuth = header->getProxyAuthenticate();
    if(!proxyAuth->type->sameAs("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test setToHeader case2]");
        break;
    }

    if(!proxyAuth->realm->sameAs("Access to the internal site")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test setToHeader case3]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderProxyAuthenticate test setToHeader case100]");

}
