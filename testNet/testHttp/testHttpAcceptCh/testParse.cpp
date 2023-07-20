#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAcceptCh acceptCh = createHttpHeaderAcceptCh();
    acceptCh->load("DPR, Viewport-Width, Width");
    auto list = acceptCh->get();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptCh test Parse case1]");
      break;
    }

    if(!list->get(0)->equals("DPR")) {
      TEST_FAIL("[HttpHeaderAcceptCh test Parse case2]");
      break;
    }

    if(!list->get(1)->equals("Viewport-Width")) {
      TEST_FAIL("[HttpHeaderAcceptCh test Parse case3]");
      break;
    }

    if(!list->get(2)->equals("Width")) {
      TEST_FAIL("[HttpHeaderAcceptCh test Parse case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCh test Parse case100]");

}
