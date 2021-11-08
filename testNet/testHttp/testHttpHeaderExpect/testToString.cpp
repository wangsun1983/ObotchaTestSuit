#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderExpect expect = createHttpHeaderExpect();
  expect->import("100-continue");
  if(!expect->toString()->equals("100-continue")) {
    printf("---[HttpHeaderExpect test toString case1] [FAILED]--- \n");
  }

  printf("---[HttpHeaderExpect test toString case100] [OK]--- \n");

}
