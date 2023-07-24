#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderFrom.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderFrom digest = createHttpHeaderFrom();
    digest->load(" webmaster@example.org");
    if(!digest->toString()->sameAs("webmaster@example.org")) {
      TEST_FAIL("[HttpHeaderFrom test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderFrom digest = createHttpHeaderFrom();
    digest->set(" webmaster@example.org");
    if(!digest->toString()->sameAs("webmaster@example.org")) {
      TEST_FAIL("[HttpHeaderFrom test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderFrom test toString case100]");
}
