#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderWarning warning = HttpHeaderWarning::New();
    warning->load("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"");
    if(warning->getCode() != 112) {
      TEST_FAIL("[HttpHeaderWarning test Parse case1]");
      break;
    }

    if(!warning->getAgent()->sameAs("-")) {
      TEST_FAIL("[HttpHeaderWarning test Parse case2]");
      break;
    }

    if(!warning->getText()->sameAs("cache down")) {
      TEST_FAIL("[HttpHeaderWarning test Parse case3]");
      break;
    }

    if(!warning->getDateTime()->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderWarning test Parse case4]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderWarning warning = HttpHeaderWarning::New();
    warning->load("110 anderson/1.3.37 \"Response is stale\"");
    if(warning->getCode() != 110) {
      TEST_FAIL("[HttpHeaderWarning test Parse case5]");
      break;
    }

    if(!warning->getAgent()->sameAs("anderson/1.3.37")) {
      TEST_FAIL("[HttpHeaderWarning test Parse case6]");
      break;
    }

    if(!warning->getText()->sameAs("Response is stale")) {
      TEST_FAIL("[HttpHeaderWarning test Parse case7]");
      break;
    }

    if(warning->getDateTime() != nullptr) {
      TEST_FAIL("[HttpHeaderWarning test Parse case8]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderWarning test Parse case100]");
}
