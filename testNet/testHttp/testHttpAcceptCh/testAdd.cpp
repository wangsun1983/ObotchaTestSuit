#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAdd() {
  while(1) {
    HttpHeaderAcceptCh acceptCh = HttpHeaderAcceptCh::New();
    acceptCh->add("DPR");
    acceptCh->add("Viewport-Width");
    acceptCh->add("Width");
    if(!acceptCh->toString()->sameAs("DPR, Viewport-Width, Width")) {
      TEST_FAIL("[HttpHeaderAcceptCh test add case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCh test add case100]");

}
