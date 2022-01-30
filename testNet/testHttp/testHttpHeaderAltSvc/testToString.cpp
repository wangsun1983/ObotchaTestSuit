#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAltSvc.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAltSvc svc = createHttpHeaderAltSvc();
    svc->import(" h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1");
    if(!svc->toString()->equals("h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1")) {
      TEST_FAIL("[HttpHeaderAltSvc test toSring case1] svc is %s",svc->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAltSvc test toSring case100]");

}
