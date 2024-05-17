#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfRange.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSetGet() {
  while(1) {
    HttpHeaderIfRange range = HttpHeaderIfRange::New();
    range->set(HttpDate::New(String::New(" Wed, 21 Oct 2015 07:28:00 GMT")));
    if(!range->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderIfRange test SetGet case1] str is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderIfRange range = HttpHeaderIfRange::New();
    range->set(String::New("abcds"));
    if(!range->toString()->sameAs("\"abcds\"")) {
      TEST_FAIL("[HttpHeaderIfRange test SetGet case8] str is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderIfRange test SetGet case100]");

}
