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

void testGetSet() {
  HttpHeaderExpectCT expect = createHttpHeaderExpectCT();
  expect->setMaxAge(86400);
  expect->setEnforce(true);
  expect->setReportUri(createString("https://foo.example/report"));
  if(!expect->toString()->equals("max-age=86400; enforce; report-uri=\"https://foo.example/report\"")) {
    TEST_FAIL("[HttpHeaderExpectCT test testGetSet case1],str is %s",expect->toString()->toChars());
  }
  
  expect->setEnforce(false);
  if(!expect->toString()->equals("max-age=86400; report-uri=\"https://foo.example/report\"")) {
    TEST_FAIL("[HttpHeaderExpectCT test testGetSet case2],str is %s",expect->toString()->toChars());
  }

  TEST_OK("[HttpHeaderExpectCT test testGetSet case100]");
}