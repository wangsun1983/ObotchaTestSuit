#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUserAgent.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderUserAgent useragent = createHttpHeaderUserAgent();
    useragent->load(" Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0");
    if(!useragent->toString()->sameAs("Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0")){
      TEST_FAIL("[HttpHeaderUserAgent test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUserAgent test toString case100]");
}
