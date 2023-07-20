#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderStrictTransportSecurity.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testTransportSecurityParse() {
  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->load("max-age=31536000; includeSubDomains;preload");
    if(security->maxAge != 31536000) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test Parse case1]");
      break;
    }

    if(!security->includeSubDomains) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test Parse case2]");
      break;
    }

    if(!security->preload) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test Parse case3]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderStrictTransportSecurity security = createHttpHeaderStrictTransportSecurity();
    security->load("max-age=31536000");
    if(security->maxAge != 31536000) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test Parse case1]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderStrictTransportSecurity test Parse case100]");

}
