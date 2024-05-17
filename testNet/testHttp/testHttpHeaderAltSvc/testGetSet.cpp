#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAltSvc.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testGetSet() {
  while(1) {
    HttpHeaderAltSvc svc = HttpHeaderAltSvc::New();
    svc->addService(String::New("h2"),
                    String::New("alt.example.com:8000"));
    svc->addService(String::New("h2"),
                    String::New(":443"));
    svc->setMaxAge(2592000);
    svc->setPersist(1);
    
    if(svc->getMaxAge() != 2592000) {
        TEST_FAIL("[HttpHeaderAltSvc test GetSet case1]");
    }
    
    if(svc->getPersist() != 1) {
        TEST_FAIL("[HttpHeaderAltSvc test GetSet case2]");
    }
    
    auto services = svc->getServices();
    
    auto s0 = services->get(0);
    if(!s0->serviceName->sameAs("h2")
        ||!s0->url->toString()->sameAs("alt.example.com:8000")) {
        TEST_FAIL("[HttpHeaderAltSvc test GetSet case3,url is %s]",s0->url->toString()->toChars());
    }
    
    auto s1 = services->get(1);
    if(!s1->serviceName->sameAs("h2")
        ||!s1->url->toString()->sameAs(":443")) {
        TEST_FAIL("[HttpHeaderAltSvc test GetSet case4,url is %s]",s1->url->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderAltSvc test GetSet case100]");

}
