#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginEmbedderPolicy.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy();
    policy->import("unsafe-none");
    
    if(!policy->toString()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy();
    policy->setAsUnSafeNone();
    
    if(!policy->toString()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy();
    policy->setAsRequireCorp();
    
    if(!policy->toString()->equals("require-corp")) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test toString case3]");
    }
    break;
  }

  TEST_OK("[CrossOriginEmbedderPolicy test toString case100]");
}