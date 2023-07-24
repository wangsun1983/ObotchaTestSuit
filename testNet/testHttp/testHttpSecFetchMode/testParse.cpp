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
    save->load("navigate");
    if(!save->get()->sameAs("navigate")) {
      TEST_FAIL("[HttpHeaderSecFetchMode test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->load("nested-navigate");
    if(!save->get()->sameAs("nested-navigate")) {
      TEST_FAIL("[HttpHeaderSecFetchMode test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchMode test Parse case100]");

}
