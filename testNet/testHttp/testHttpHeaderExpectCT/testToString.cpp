#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpectCT.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderExpectCT expect = createHttpHeaderExpectCT();
  expect->load("max-age=86400; enforce; report-uri=\"https://foo.example/report\"");
  if(!expect->toString()->equals("max-age=86400; enforce; report-uri=\"https://foo.example/report\"")) {
    TEST_FAIL("[HttpHeaderExpectCT test toString case1],str is %s",expect->toString()->toChars());
  }
  
  HttpHeader header = createHttpHeader();
  header->setExpectCT(expect);
  auto expect2 = header->getExpectCT();
  if(!expect2->toString()->equals("max-age=86400; enforce; report-uri=\"https://foo.example/report\"")) {
    TEST_FAIL("[HttpHeaderExpectCT test toString case2]");
  }
  
  TEST_OK("[HttpHeaderExpectCT test toString case100]");
}
