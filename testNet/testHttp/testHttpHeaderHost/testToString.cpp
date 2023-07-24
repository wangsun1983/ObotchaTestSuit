#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderHost.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderHost digest = createHttpHeaderHost();
    digest->load(" developer.mozilla.org:1234");
    if(!digest->toString()->sameAs("developer.mozilla.org:1234")) {
      TEST_FAIL("[HttpHeaderHost test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderHost digest = createHttpHeaderHost();
    digest->load(" developer.mozilla.org");
    if(!digest->toString()->sameAs("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderHost test toString case100]");
}
