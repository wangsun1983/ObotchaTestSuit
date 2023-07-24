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
    svc->load(" h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1");
    if(!svc->toString()->sameAs("h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1")) {
      TEST_FAIL("[HttpHeaderAltSvc test toSring case1] svc is %s",svc->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAltSvc svc = createHttpHeaderAltSvc();
    svc->addService(createString("h2"),
                    createString("alt.example.com:8000"));
    svc->addService(createString("h2"),
                    createString(":443"));
    svc->setMaxAge(2592000);
    svc->setPersist(1);
    if(!svc->toString()->sameAs("h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1")) {
      TEST_FAIL("[HttpHeaderAltSvc test toSring case2] svc is [%s]",svc->toString()->toChars());
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderAltSvc test toSring case100]");

}
