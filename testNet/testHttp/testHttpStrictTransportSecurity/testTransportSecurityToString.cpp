#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderStrictTransportSecurity.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testTransportSecurityToString() {
  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->load("max-age=31536000;preload,includeSubDomains");
    if(!security->toString()->sameAs("max-age=31536000;preload;includeSubDomains")) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test toString case1],security is %s",security->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->load("max-age=31536000");
    if(!security->toString()->sameAs("max-age=31536000")) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderStrictTransportSecurity test toString case100]");
}
