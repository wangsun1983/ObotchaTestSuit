#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderContentLength.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentLength upgrade = createHttpHeaderContentLength();
    upgrade->load(" 123 ");
    if(!upgrade->toString()->sameAs("123")) {
      TEST_FAIL("[HttpHeaderContentLength test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLength test toString case100]");
}
