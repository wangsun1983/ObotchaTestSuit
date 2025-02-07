#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderWarning warning = HttpHeaderWarning::New();
  warning->load("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"");
  if(!warning->toString()->sameAs("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"")) {
    TEST_FAIL("[HttpHeaderWarning test toString case1],warn is %s",warning->toString()->toChars());
    return;
  }

  warning = HttpHeaderWarning::New();
  warning->load("110 anderson/1.3.37 \"Response is stale\"");
  if(!warning->toString()->sameAs("110 anderson/1.3.37 \"Response is stale\"")) {
    TEST_FAIL("[HttpHeaderWarning test toString case2] warn is %s",warning->toString()->toChars());
    return;
  }

  TEST_OK("[HttpHeaderWarning test toString case100]");
}
