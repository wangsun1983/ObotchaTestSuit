#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderDate.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderDate headerDate = createHttpHeaderDate();
    headerDate->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!headerDate->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderDate test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderDate test toString case100]");

}
