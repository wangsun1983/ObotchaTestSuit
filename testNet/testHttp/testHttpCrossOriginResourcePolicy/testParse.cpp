#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginResourcePolicy.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->import("same-site");
    if(!policy->isSameSite()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->import("same-origin");
    if(!policy->isSameOrigin()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case2]");
    }
    break;
  }


  while(1) {
    HttpHeaderCrossOriginResourcePolicy policy = createHttpHeaderCrossOriginResourcePolicy();
    policy->import("cross-origin");
    if(!policy->isCrossOrigin()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case3]");
    }
    break;
  }


  TEST_OK("[CrossOriginOpenerPolicy test Parse case100]");
}
