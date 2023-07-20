#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderContentEncoding.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentEncoding c = createHttpHeaderContentEncoding();
    c->load("gzip, deflate");
    auto list = c->get();
    if(!list->get(0)->equals("gzip")) {
      TEST_FAIL("[HttpHeaderContentEncoding test Parse case1]");
      break;
    }

    if(!list->get(1)->equals("deflate")) {
      TEST_FAIL("[HttpHeaderContentEncoding test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentEncoding test Parse case100]");

}
