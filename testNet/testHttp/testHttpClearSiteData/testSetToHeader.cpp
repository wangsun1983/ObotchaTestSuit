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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Clear-Site-Data"),
                createString("\"cache\", \"cookies\", \"storage\", \"executionContexts\""));

    auto c = header->getClearSiteData();
    if(!c->isCache()) {
      TEST_FAIL("[HttpHeaderClearSiteData test setToHeader case1]");
      break;
    }

    if(!c->isCookies()) {
      TEST_FAIL("[HttpHeaderClearSiteData test setToHeader case2]");
      break;
    }

    if(!c->isStorage()) {
      TEST_FAIL("[HttpHeaderClearSiteData test setToHeader case3]");
      break;
    }

    if(!c->isExecutionContexts()) {
      TEST_FAIL("[HttpHeaderClearSiteData test setToHeader case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderClearSiteData test setToHeader case100]");
}
