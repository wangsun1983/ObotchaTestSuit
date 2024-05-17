#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderExpect expect = HttpHeaderExpect::New();
    expect->load("100-continue");
    auto str = expect->get();
    if(!str->sameAs("100-continue")) {
      TEST_FAIL("[HttpHeaderExpect test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderExpect expect = HttpHeaderExpect::New();
    bool isException = false;
    try {
      expect->load("123-continue");
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[HttpHeaderExpect test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderExpect test Parse case100]");

}
