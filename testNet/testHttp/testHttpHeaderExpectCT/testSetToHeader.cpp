#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpectCT.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Expect-CT"),
                String::New("max-age=86400; enforce; report-uri=\"https://foo.example/report\""));
    auto expect = header->getExpectCT();
    if(expect->getMaxAge() != 86400) {
      TEST_FAIL("[HttpHeaderExpectCT test setToHeader case1]");
      break;
    }

    if(!expect->isEnforce()) {
      TEST_FAIL("[HttpHeaderExpectCT test setToHeader case2]");
      break;
    }

    if(!expect->getReportUri()->toString()->sameAs("https://foo.example/report")) {
      TEST_FAIL("[HttpHeaderExpectCT test setToHeader case3],url is [%s]",expect->getReportUri()->toString()->toChars());
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderExpectCT test setToHeader case100]");

}
