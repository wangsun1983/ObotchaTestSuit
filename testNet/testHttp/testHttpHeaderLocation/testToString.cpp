#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLocation.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderLocation location = createHttpHeaderLocation();
    location->import("/index.html");
    if(!location->toString()->equals("/index.html")) {
      TEST_FAIL("[HttpHeaderLocation test toString case1],str is %s",location->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderLocation test toString case100]");

}
