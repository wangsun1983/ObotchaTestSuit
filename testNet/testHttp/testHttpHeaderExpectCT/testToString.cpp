#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpectCT.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderExpectCT expect = createHttpHeaderExpectCT();
  expect->import("max-age=86400; enforce; report-uri=\"https://foo.example/report\"");
  if(!expect->toString()->equals("max-age=86400; enforce; report-uri=\"https://foo.example/report\"")) {
    printf("---[HttpHeaderExpectCT test toString case1] [FAILED]--- \n");
  }

  printf("---[HttpHeaderExpectCT test toString case100] [OK]--- \n");
}
