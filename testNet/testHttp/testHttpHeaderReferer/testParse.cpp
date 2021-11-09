#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("");
    HttpUrl url = match->get();
    if(url == nullptr){
      printf("---[HttpHeaderReferer test parse case1] [FAILED]--- \n");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderReferer match = createHttpHeaderReferer();
    match->import("https://developer.mozilla.org:1234");
    HttpUrl url = match->get();
    if(url == nullptr){
      printf("---[HttpHeaderReferer test parse case2] [FAILED]--- \n");
      break;
    }

    if(!url->getScheme()->equals("https")) {
      printf("---[HttpHeaderReferer test parse case3] [FAILED]--- \n");
      break;
    }

    if(!url->getHost()->equals("developer.mozilla.org")) {
      printf("---[HttpHeaderReferer test parse case4] [FAILED]--- \n");
      break;
    }

    if(url->getPort() != 1234) {
      printf("---[HttpHeaderReferer test parse case5] [FAILED]--- \n");
      break;
    }

    break;
  }
  printf("---[HttpHeaderReferer test Parse case100] [OK]--- \n");
}
