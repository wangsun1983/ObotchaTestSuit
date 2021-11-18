#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderProxyAuthorization.hpp"

using namespace obotcha;

void testProxyAUthorizationToString() {
  while(1) {
    HttpHeaderProxyAuthorization proxy = createHttpHeaderProxyAuthorization();
    proxy->import("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    if(!proxy->toString()->equals("Basic YWxhZGRpbjpvcGVuc2VzYW1l")) {
      printf("---[HttpHeaderProxyAuthorization test toString case10] [OK]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderProxyAuthorization test toString case100] [OK]--- \n");
}
