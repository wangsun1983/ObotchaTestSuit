#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderFrom.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderFrom digest = createHttpHeaderFrom();
    digest->import(" developer.mozilla.org");
    if(!digest->toString()->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderFrom test Parse case1]");
      break;
    }
    
    if(!digest->get()->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderFrom test Parse case1_1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderFrom test Parse case100]");
}
