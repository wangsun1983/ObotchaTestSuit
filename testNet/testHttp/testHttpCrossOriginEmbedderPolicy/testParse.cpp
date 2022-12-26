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
#include "HttpHeaderCrossOriginEmbedderPolicy.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy();
    policy->import("unsafe-none");
    if(!policy->get()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test Parse case1]，policy is %s",policy->get()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy(createString("unsafe-none"));
    if(!policy->get()->equals("unsafe-none")) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test Parse case2]，policy is %s",policy->get()->toChars());
    }
    break;
  }

  TEST_OK("[CrossOriginEmbedderPolicy test Parse case100]");
}
