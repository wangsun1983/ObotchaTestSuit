#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderStrictTransportSecurity.hpp"

using namespace obotcha;

void testTransportSecurityToString() {
  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->import("max-age=31536000;preload,includeSubDomains");
    if(!security->toString()->equals("max-age=31536000;preload;includeSubDomains")) {
      printf("---[HttpHeaderStrictTransportSecurity test toString case1] [FAILED]---,security is %s \n",security->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->import("max-age=31536000");
    if(!security->toString()->equals("max-age=31536000")) {
      printf("---[HttpHeaderStrictTransportSecurity test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderStrictTransportSecurity test toString case100] [OK]--- \n");
}
