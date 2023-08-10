#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderClearSiteData.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderClearSiteData c = createHttpHeaderClearSiteData();
    c->load("\"cache\", \"cookies\", \"storage\", \"executionContexts\"");
    if(!c->isCache()) {
      TEST_FAIL("[HttpHeaderClearSiteData test Parse case1]");
      break;
    }

    if(!c->isCookies()) {
      TEST_FAIL("[HttpHeaderClearSiteData test Parse case2]");
      break;
    }

    if(!c->isStorage()) {
      TEST_FAIL("[HttpHeaderClearSiteData test Parse case3]");
      break;
    }

    if(!c->isExecutionContexts()) {
      TEST_FAIL("[HttpHeaderClearSiteData test Parse case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderClearSiteData test Parse case100]");
}
