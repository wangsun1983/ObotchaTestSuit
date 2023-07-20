#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderHost.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderHost digest = createHttpHeaderHost();
    digest->load(" developer.mozilla.org:1234");
    auto host = digest->getHost();
    if(!host->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test Parse case1] host is%s\n",host->toChars());
      break;
    }

    if(digest->getPort() != 1234) {
      TEST_FAIL("[HttpHeaderHost test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderHost digest = createHttpHeaderHost();
    digest->load(" developer.mozilla.org");
    auto host = digest->getHost();
    if(!host->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test Parse case3]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderHost digest = createHttpHeaderHost();
    digest->setHost(" developer.mozilla.org");
    auto host = digest->getHost();
    if(!host->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test Parse case4]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderHost test Parse case100]");
}
