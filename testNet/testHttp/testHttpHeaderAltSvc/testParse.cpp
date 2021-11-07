#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAltSvc.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAltSvc svc = createHttpHeaderAltSvc();
    svc->import(" h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1");
    auto svcList = svc->getServices();
    if(svcList->size() != 2) {
      printf("---[HttpHeaderAltSvc test Parse case1] [FAILED]--- \n");
      break;
    }

    auto item1 = svcList->get(0);
    if(!item1->serviceName->equals("h2")) {
      printf("---[HttpHeaderAltSvc test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!item1->url->getHost()->equals("alt.example.com")) {
      printf("---[HttpHeaderAltSvc test Parse case3] [FAILED]--- \n");
      break;
    }

    if(item1->url->getPort() != 8000) {
      printf("---[HttpHeaderAltSvc test Parse case4] [FAILED]--- port is %d\n",item1->url->getPort());
      break;
    }

    auto item2 = svcList->get(1);
    if(!item2->serviceName->equals("h2")) {
      printf("---[HttpHeaderAltSvc test Parse case5] [FAILED]--- \n");
      break;
    }

    if(item2->url->getHost() != nullptr) {
      printf("---[HttpHeaderAltSvc test Parse case6] [FAILED]--- \n");
      break;
    }

    if(item2->url->getPort() != 443) {
      printf("---[HttpHeaderAltSvc test Parse case7] [FAILED]--- \n");
      break;
    }

    if(svc->getMaxAge() != 2592000) {
      printf("---[HttpHeaderAltSvc test Parse case8] [FAILED]--- \n");
      break;
    }

    if(svc->getPersist() != 1) {
      printf("---[HttpHeaderAltSvc test Parse case9] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderAltSvc test Parse case100] [OK]--- \n");

}
