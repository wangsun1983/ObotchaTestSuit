#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentLocation.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentLocation location = createHttpHeaderContentLocation();
    location->load("/index.html");
    if(!location->toString()->sameAs("/index.html")) {
      TEST_FAIL("[HttpHeaderContentLocation test toString case1],str is %s",location->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLocation test toString case100]");

}
