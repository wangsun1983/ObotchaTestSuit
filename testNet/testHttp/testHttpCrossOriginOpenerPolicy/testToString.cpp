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
    HttpHeaderCrossOriginOpenerPolicy policy = HttpHeaderCrossOriginOpenerPolicy::New();
    policy->load("unsafe-none");
    
    if(!policy->toString()->sameAs("unsafe-none")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = HttpHeaderCrossOriginOpenerPolicy::New();
    policy->setAsUnSafeNone();
    
    if(!policy->toString()->sameAs("unsafe-none")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = HttpHeaderCrossOriginOpenerPolicy::New();
    policy->setAsSameOrigin();
    
    if(!policy->toString()->sameAs("same-origin")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case3]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = HttpHeaderCrossOriginOpenerPolicy::New();
    policy->setAsSameOriginAllowPopups();
    
    if(!policy->toString()->sameAs("same-origin-allow-popups")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test toString case4]");
    }
    break;
  }

  TEST_OK("[CrossOriginOpenerPolicy test toString case100]");
}
