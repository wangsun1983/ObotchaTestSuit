#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchMode.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("navigate");
    if(!save->get()->equals("navigate")) {
      TEST_FAIL("[HttpHeaderSecFetchMode test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("nested-navigate");
    if(!save->get()->equals("nested-navigate")) {
      TEST_FAIL("[HttpHeaderSecFetchMode test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchMode test Parse case100]");

}
