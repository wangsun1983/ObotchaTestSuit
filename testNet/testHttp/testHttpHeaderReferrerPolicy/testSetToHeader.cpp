#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferrerPolicy.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Referrer-Policy"),
                createString("no-referrer, strict-origin-when-cross-origin"));
    auto match = header->getRefererPolicy();
    ArrayList<String> list = match->get();
    if(list->size() != 2) {
      TEST_FAIL("[HttpHeaderReferrerPolicy setToHeader case1] ");
      break;
    }

    if(!list->get(0)->equals("no-referrer") || !list->get(1)->equals("strict-origin-when-cross-origin")) {
      TEST_FAIL("[HttpHeaderReferrerPolicy setToHeader case2] ");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderReferrerPolicy setToHeader case100]");
}