#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderContentEncoding.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentEncoding c = createHttpHeaderContentEncoding();
    c->import("gzip, deflate");
    auto list = c->get();
    if(!list->get(0)->equals("gzip")) {
      printf("---[HttpHeaderClearSiteData test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("deflate")) {
      printf("---[HttpHeaderClearSiteData test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderClearSiteData test Parse case100] [OK]--- \n");

}
