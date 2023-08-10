#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentLocation.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentLocation location = createHttpHeaderContentLocation();
    location->load("/index.html");
    if(location->get() == nullptr || !location->get()->sameAs("/index.html")) {
      TEST_FAIL("[HttpHeaderContentLocation test Parse case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLocation test Parse case100]");

}
