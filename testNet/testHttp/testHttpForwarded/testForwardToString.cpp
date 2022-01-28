#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderForwarded.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testForwardedToString() {
  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("For=\"[2001:db8:cafe::17]:4711\"");
    if(!encoding1->toString()->equalsIgnoreCase("For=\"[2001:db8:cafe::17]:4711\"")) {
      TEST_FAIL("[HttpHeaderForwarded test toString case1],forwarded is %s",encoding1->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("for=\"_mdn\"");
    if(!encoding1->toString()->equalsIgnoreCase("for=\"_mdn\"")) {
      TEST_FAIL("[HttpHeaderForwarded test toString case2] forwarded is %s",encoding1->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("for=192.0.2.60; proto=http; by=203.0.113.43");
    if(!encoding1->toString()->equalsIgnoreCase("for=192.0.2.60; proto=http; by=203.0.113.43")) {
      TEST_FAIL("[HttpHeaderForwarded test toString case3],encoding is %s",encoding1->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderForwarded test toString case100]");

}
