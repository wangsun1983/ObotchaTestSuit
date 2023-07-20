#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServer.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderServer match = createHttpHeaderServer();
    match->load("Apache/2.4.1 (Unix)");
    if(!match->get()->equals("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test Parse case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderServer test Parse case100]");
}
