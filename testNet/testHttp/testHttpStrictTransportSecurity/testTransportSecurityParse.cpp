#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderStrictTransportSecurity.hpp"
#include "Math.hpp"

using namespace obotcha;

void testTransportSecurityParse() {
  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->import("max-age=31536000; includeSubDomains;preload");
    if(security->maxAge != 31536000) {
      printf("---[HttpHeaderStrictTransportSecurity test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!security->includeSubDomains) {
      printf("---[HttpHeaderStrictTransportSecurity test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!security->preload) {
      printf("---[HttpHeaderStrictTransportSecurity test Parse case3] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->import("max-age=31536000");
    if(security->maxAge != 31536000) {
      printf("---[HttpHeaderStrictTransportSecurity test Parse case1] [FAILED]--- \n");
      break;
    }

    break;
  }
  printf("---[HttpHeaderStrictTransportSecurity test Parse case100] [OK]--- \n");

}
