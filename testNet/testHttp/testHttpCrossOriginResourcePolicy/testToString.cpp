#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginResourcePolicy.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->import("same-origin ");
    
    if(!policy->toString()->equals("same-origin")) {
      TEST_FAIL("[CrossOriginResourcePolicy test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->setAsSameOrigin();
    
    if(!policy->toString()->equals("same-origin")) {
      TEST_FAIL("[CrossOriginResourcePolicy test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->setAsCrossOrigin();
    
    if(!policy->toString()->equals("cross-origin")) {
      TEST_FAIL("[CrossOriginResourcePolicy test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->setAsSameSite();
    
    if(!policy->toString()->equals("same-site")) {
      TEST_FAIL("[CrossOriginResourcePolicy test toString case3]");
    }
    break;
  }

  TEST_OK("[CrossOriginResourcePolicy test toString case100]");
}