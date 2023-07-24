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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Upgrade"),
                createString(" websocket "));
    auto upgrade = header->getUpgrade();
    if(!upgrade->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test setToHeader case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test setToHeader case100]");
}
