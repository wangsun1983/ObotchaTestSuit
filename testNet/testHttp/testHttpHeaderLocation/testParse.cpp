#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLocation.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderLocation location = createHttpHeaderLocation();
    location->load("/index.html");
    if(location->get() == nullptr || !location->get()->equals("/index.html")) {
      TEST_FAIL("[HttpHeaderLocation test Parse case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderLocation test Parse case100]");

}
