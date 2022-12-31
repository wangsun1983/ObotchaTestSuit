#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderStrictTransportSecurity.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Strict-Transport-Security"),
                createString(" max-age=31536000; includeSubDomains;preload"));
    auto security = header->getStrictTransportSecurity();
    if(security->maxAge != 31536000) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test setToHeader case1]");
      break;
    }

    if(!security->includeSubDomains) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test setToHeader case2]");
      break;
    }

    if(!security->preload) {
      TEST_FAIL("[HttpHeaderStrictTransportSecurity test setToHeader case3]");
      break;
    }
    break;
  }
  
  TEST_OK("[HttpHeaderStrictTransportSecurity test setToHeader case100]");

}
