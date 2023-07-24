#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!range->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderIfRange test toString case1] str is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderIfRange range = createHttpHeaderIfRange();
    range->load("\"abcds\"");
    if(!range->toString()->sameAs("\"abcds\"")) {
      TEST_FAIL("[HttpHeaderIfRange test toString case8] str is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderIfRange test toString case100]");

}
