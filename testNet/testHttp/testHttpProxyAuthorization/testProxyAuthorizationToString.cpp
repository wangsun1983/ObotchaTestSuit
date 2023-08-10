#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthorization.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testProxyAUthorizationToString() {
  while(1) {
    HttpHeaderProxyAuthorization proxy = createHttpHeaderProxyAuthorization();
    proxy->load("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    if(!proxy->toString()->sameAs("Basic YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderProxyAuthorization test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderProxyAuthorization proxy = createHttpHeaderProxyAuthorization();
    proxy->load("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    header->setProxyAuthorization(proxy);
    
    auto proxy2 = header->getProxyAuthorization();
    if(!proxy2->toString()->sameAs("Basic YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderProxyAuthorization test toString case2]");
    }
    break;
  }


  TEST_OK("[HttpHeaderProxyAuthorization test toString case100]");
}
