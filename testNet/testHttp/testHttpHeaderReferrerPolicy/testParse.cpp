#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferrerPolicy.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderReferrerPolicy match = createHttpHeaderReferrerPolicy();
    match->load("no-referrer, strict-origin-when-cross-origin");

    ArrayList<String> list = match->get();
    if(list->size() != 2) {
      TEST_FAIL("[HttpHeaderReferrerPolicy test Parse case1] ");
      break;
    }

    if(!list->get(0)->equals("no-referrer") || !list->get(1)->equals("strict-origin-when-cross-origin")) {
      TEST_FAIL("[HttpHeaderReferrerPolicy test Parse case2] ");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderReferrerPolicy test Parse case100]");
}
