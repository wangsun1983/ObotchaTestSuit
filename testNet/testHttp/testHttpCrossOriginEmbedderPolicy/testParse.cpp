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
    policy->load("unsafe-none");
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test Parse case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy(createString("unsafe-none"));
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test Parse case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderCrossOriginEmbedderPolicy policy = createHttpHeaderCrossOriginEmbedderPolicy();
    policy->load("require-corp");
    if(!policy->isRequireCorp()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test Parse case3]");
    }
    break;
  }

  TEST_OK("[CrossOriginEmbedderPolicy test Parse case100]");
}
