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

  TEST_OK("[CrossOriginOpenerPolicy test toString case100]");
}
