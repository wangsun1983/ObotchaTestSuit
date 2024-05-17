#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfUnmodifiedSince.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpHeaderIfUnmodifiedSince modifiedSince = HttpHeaderIfUnmodifiedSince::New();
    modifiedSince->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!modifiedSince->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderIfUnmodifiedSince test toString case1] date is %s",modifiedSince->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderIfUnmodifiedSince test toString case100]");

}
