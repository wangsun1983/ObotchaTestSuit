#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthenticate.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testProxyAuthenticateToString() {
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->load("Basic");

    if(!proxyAuth->toString()->sameAs("Basic")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test toString case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->load("Basic realm=\"Access to the internal site\"");

    if(!proxyAuth->toString()->sameAs("Basic realm=\"Access to the internal site\"")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test toString case2] auth is %s",proxyAuth->toString()->toChars());
        break;
    }

    break;
  }
  
  while(1) {
    HttpHeaderProxyAuthenticate proxyAuth = createHttpHeaderProxyAuthenticate();
    proxyAuth->load("Basic realm=\"Access to the internal site\"");
    HttpHeader header = createHttpHeader();
    header->setProxyAuthenticate(proxyAuth);
    
    auto proxy = header->getProxyAuthenticate();
    if(!proxy->toString()->sameAs("Basic realm=\"Access to the internal site\"")) {
        TEST_FAIL("[HttpHeaderProxyAuthenticate test toString case3] auth is %s",proxyAuth->toString()->toChars());
        break;
    }
    
    break;
  }


  TEST_OK("[HttpHeaderProxyAuthenticate test toString case100]");

}
