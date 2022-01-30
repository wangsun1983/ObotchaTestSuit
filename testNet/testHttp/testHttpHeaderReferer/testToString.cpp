#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("");

    if(!match->toString()->equals("")){
      TEST_FAIL("[HttpHeaderReferer test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("https://developer.mozilla.org:1234");
    if(!match->toString()->equals("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderReferer test toString case2]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderReferer test toString case100]");
}
