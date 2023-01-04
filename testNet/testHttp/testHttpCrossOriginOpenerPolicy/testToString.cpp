#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginOpenerPolicy.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->import("unsafe-none");
    
    if(!policy->toString()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->setAsUnSafeNone();
    
    if(!policy->toString()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->setAsSameOrigin();
    
    if(!policy->toString()->equals("same-origin")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case3]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->setAsSameOriginAllowPopups();
    
    if(!policy->toString()->equals("same-origin-allow-popups")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case4]");
    }
    break;
  }

  TEST_OK("[CrossOriginOpenerPolicy test toString case100]");
}
