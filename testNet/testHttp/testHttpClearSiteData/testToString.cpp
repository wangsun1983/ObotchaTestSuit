#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderClearSiteData.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    printf("start to Stirng test \n");
    HttpHeaderClearSiteData c = createHttpHeaderClearSiteData();
    c->import("\"cache\", \"cookies\", \"storage\", \"executionContexts\"");

    HttpHeaderClearSiteData c2 = createHttpHeaderClearSiteData(c->toString());

    if(c->isCache() != c2->isCache()) {
      printf("---[HttpHeaderClearSiteData test toString case1] [FAILED]--- \n");
      break;
    }

    if(c->isCookies() != c2->isCookies()) {
      printf("---[HttpHeaderClearSiteData test toString case2] [FAILED]--- \n");
      break;
    }

    if(c->isStorage() != c2->isStorage()) {
      printf("---[HttpHeaderClearSiteData test toString case3] [FAILED]--- \n");
      break;
    }

    if(c->isExecutionContexts() != c2->isExecutionContexts()) {
      printf("---[HttpHeaderClearSiteData test toString case4] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderClearSiteData test toString case100] [OK]--- \n");

}
