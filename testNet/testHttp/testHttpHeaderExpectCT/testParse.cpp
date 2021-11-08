#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpectCT.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderExpectCT expect = createHttpHeaderExpectCT();
    expect->import("max-age=86400; enforce; report-uri=\"https://foo.example/report\"");
    if(expect->getMaxAge() != 86400) {
      printf("---[HttpHeaderExpectCT test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!expect->isEnforce()) {
      printf("---[HttpHeaderExpectCT test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!expect->getReportUri()->toString()->equals("https://foo.example/report")) {
      printf("---[HttpHeaderExpectCT test Parse case3] [FAILED]---,url is [%s] \n",expect->getReportUri()->toString()->toChars());
      break;
    }
    break;
  }


  printf("---[HttpHeaderExpectCT test Parse case100] [OK]--- \n");

}
