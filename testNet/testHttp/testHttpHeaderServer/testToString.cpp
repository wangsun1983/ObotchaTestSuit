#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderServer match = createHttpHeaderServer();
    match->import("Apache/2.4.1 (Unix)");
    if(!match->toString()->equals("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderServer test toString case100]");
}
