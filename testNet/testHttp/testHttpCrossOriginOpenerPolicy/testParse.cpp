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
#include "HttpHeaderCrossOriginOpenerPolicy.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->load("unsafe-none");
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->load("same-origin");
    if(!policy->isSameOrigin()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginOpenerPolicy policy = createHttpHeaderCrossOriginOpenerPolicy();
    policy->load("same-origin-allow-popups");
    if(!policy->isSameOriginAllowPopups()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case3]");
    }
    break;
  }

  TEST_OK("[CrossOriginOpenerPolicy test Parse case1]");
}
