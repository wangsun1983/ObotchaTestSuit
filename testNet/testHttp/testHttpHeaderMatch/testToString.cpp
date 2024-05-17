#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderMatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderMatch match = HttpHeaderMatch::New();
    match->load("\"bfc13a64729c4290ef5b2c2730249c88ca92d82d\"");
    if(!match->toString()->sameAs("\"bfc13a64729c4290ef5b2c2730249c88ca92d82d\"")) {
      TEST_FAIL("[HttpHeaderMatch test toString case1],s is %s",match->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = HttpHeaderMatch::New();
    match->load("W/\"67ab43\", \"54ed21\", \"7892dd\"");
    if(!match->toString()->sameAs("W/\"67ab43\", \"54ed21\", \"7892dd\"")) {
      TEST_FAIL("[HttpHeaderMatch test toString case2]");
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = HttpHeaderMatch::New();
    match->load("*");
    if(!match->toString()->sameAs("*")) {
      TEST_FAIL("[HttpHeaderMatch test toString case3],match is %s",match->toString()->toChars());
    }

    break;
  }

  TEST_OK("[HttpHeaderMatch test toString case100]");
}
