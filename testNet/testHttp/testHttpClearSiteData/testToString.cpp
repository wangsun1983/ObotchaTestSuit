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
    c->load("\"cache\", \"cookies\", \"storage\", \"executionContexts\"");
    if(!c->toString()->sameAs("\"cache\",\"cookies\",\"executionContexts\",\"storage\"")){
      TEST_FAIL("[HttpHeaderClearSiteData test toString case1],str is %s",c->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderClearSiteData c = createHttpHeaderClearSiteData();
    c->setCache(true);
    c->setCookies(true);
    c->setExecutionContexts(true);
    c->setStorage(true);
    if(!c->toString()->sameAs("\"cache\",\"cookies\",\"executionContexts\",\"storage\"")){
      TEST_FAIL("[HttpHeaderClearSiteData test toString case2],str is %s",c->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderClearSiteData test toString case100]");

}
