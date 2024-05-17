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
    HttpHeaderUpgrade upgrade = HttpHeaderUpgrade::New();
    upgrade->load(" websocket ");
    if(!upgrade->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test Parse case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderUpgrade upgrade = HttpHeaderUpgrade::New(" websocket ");
    if(!upgrade->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test Parse case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test Parse case100]");
}
