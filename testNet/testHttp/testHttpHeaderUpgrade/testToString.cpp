#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->import(" websocket ");
    if(!upgrade->toString()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test toString case100]");
}
