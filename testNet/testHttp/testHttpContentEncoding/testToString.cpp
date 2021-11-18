#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderContentEncoding.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentEncoding c = createHttpHeaderContentEncoding();
    c->import("gzip, deflate");
    if(!c->toString()->equals("gzip, deflate")) {
      printf("---[HttpHeaderClearSiteData test toString case1] [OK]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderClearSiteData test toString case100] [OK]--- \n");

}
