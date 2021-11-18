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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderClearSiteData c = createHttpHeaderClearSiteData();
    c->import("\"cache\", \"cookies\", \"storage\", \"executionContexts\"");
    if(!c->isCache()) {
      printf("---[HttpHeaderClearSiteData test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!c->isCookies()) {
      printf("---[HttpHeaderClearSiteData test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!c->isStorage()) {
      printf("---[HttpHeaderClearSiteData test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!c->isExecutionContexts()) {
      printf("---[HttpHeaderClearSiteData test Parse case4] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderClearSiteData test Parse case100] [OK]--- \n");

}
