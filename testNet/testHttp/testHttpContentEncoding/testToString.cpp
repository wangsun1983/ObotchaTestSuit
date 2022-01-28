#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderContentEncoding.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentEncoding c = createHttpHeaderContentEncoding();
    c->import("gzip, deflate");
    if(!c->toString()->equals("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderClearSiteData test toString case1] [OK] \n");
      break;
    }
    break;
  }

  TEST_FAIL("[HttpHeaderClearSiteData test toString case100] [OK] \n");

}
