#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderClearSiteData.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderClearSiteData c = createHttpHeaderClearSiteData();
    c->import("\"cache\", \"cookies\", \"storage\", \"executionContexts\"");

    HttpHeaderClearSiteData c2 = createHttpHeaderClearSiteData(c->toString());

    if(c->isCache() != c2->isCache()) {
      TEST_FAIL("[HttpHeaderClearSiteData test toString case1]");
      break;
    }

    if(c->isCookies() != c2->isCookies()) {
      TEST_FAIL("[HttpHeaderClearSiteData test toString case2]");
      break;
    }

    if(c->isStorage() != c2->isStorage()) {
      TEST_FAIL("[HttpHeaderClearSiteData test toString case3]");
      break;
    }

    if(c->isExecutionContexts() != c2->isExecutionContexts()) {
      TEST_FAIL("[HttpHeaderClearSiteData test toString case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderClearSiteData test toString case100]");

}
