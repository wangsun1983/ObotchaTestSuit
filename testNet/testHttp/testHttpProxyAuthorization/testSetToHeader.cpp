#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthorization.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Proxy-Authorization"),
                createString("Basic YWxhZGRpbjpvcGVuc2VzYW1l"));
    auto proxy = header->getProxyAuthorization();
    if(!proxy->type->sameAs("Basic")) {
      TEST_FAIL("[HttpHeaderProxyAuthorization test setToHeader case10]");
    }

    if(!proxy->credentials->sameAs("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderProxyAuthorization test setToHeader case10]");
    }

    break;
  }

  TEST_OK("[HttpHeaderProxyAuthorization test setToHeader case100]");
}
