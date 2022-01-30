#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->import(" websocket ");
    if(!upgrade->get()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test Parse case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test Parse case100]");
}
