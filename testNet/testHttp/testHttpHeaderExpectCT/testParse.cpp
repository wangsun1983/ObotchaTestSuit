#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpectCT.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderExpectCT expect = createHttpHeaderExpectCT();
    expect->import("max-age=86400; enforce; report-uri=\"https://foo.example/report\"");
    if(expect->getMaxAge() != 86400) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case1]");
      break;
    }

    if(!expect->isEnforce()) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case2]");
      break;
    }

    if(!expect->getReportUri()->toString()->equals("https://foo.example/report")) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case3],url is [%s]",expect->getReportUri()->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderExpectCT expect = createHttpHeaderExpectCT("max-age=86400; enforce; report-uri=\"https://foo.example/report\"");
    if(expect->getMaxAge() != 86400) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case4]");
      break;
    }

    if(!expect->isEnforce()) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case5]");
      break;
    }

    if(!expect->getReportUri()->toString()->equals("https://foo.example/report")) {
      TEST_FAIL("[HttpHeaderExpectCT test Parse case6],url is [%s]",expect->getReportUri()->toString()->toChars());
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderExpectCT test Parse case100]");

}
