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
    policy->import("unsafe-none");
    if(!policy->get()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginOpenerPolicy test Parse case1]，policy is %s",policy->get()->toChars());
    }
    break;
  }

  TEST_OK("[CrossOriginOpenerPolicy test Parse case1]");
}
