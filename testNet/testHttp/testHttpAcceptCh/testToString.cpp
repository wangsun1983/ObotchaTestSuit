#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAcceptCh acceptCh = HttpHeaderAcceptCh::New();
    acceptCh->load("DPR, Viewport-Width, Width");
    if(!acceptCh->toString()->sameAs("DPR, Viewport-Width, Width")) {
      TEST_FAIL("[HttpHeaderAcceptCh test toString case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCh test toString case100]");

}
