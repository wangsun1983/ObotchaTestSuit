#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfModifiedSince.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpHeaderIfModifiedSince modifiedSince = createHttpHeaderIfModifiedSince();
    modifiedSince->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!modifiedSince->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test toString case1] date is %s",modifiedSince->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderIfModifiedSince test toString case100]");

}
