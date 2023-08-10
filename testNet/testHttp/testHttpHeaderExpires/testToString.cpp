#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderExpires.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderExpires headerDate = createHttpHeaderExpires();
    headerDate->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!headerDate->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderExpires test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderExpires test toString case100]");

}
