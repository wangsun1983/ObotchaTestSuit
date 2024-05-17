#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLink.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkToString() {
  while(1) {
    HttpHeaderLink link1 = HttpHeaderLink::New("<https://example.com>; rel=\"preload\"");
    if(!link1->toString()->sameAs("<https://example.com>; rel=\"preload\"")) {
      TEST_FAIL("[HttpHeaderLink test toString case1] link is %s",link1->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderLink test toString case100]");
}
