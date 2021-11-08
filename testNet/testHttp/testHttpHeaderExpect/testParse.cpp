#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderExpect expect = createHttpHeaderExpect();
    expect->import("100-continue");
    auto str = expect->get();
    if(!str->equals("100-continue")) {
      printf("---[HttpHeaderExpect test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderExpect expect = createHttpHeaderExpect();
    bool isException = false;
    try {
      expect->import("123-continue");
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      printf("---[HttpHeaderExpect test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderExpect test Parse case100] [OK]--- \n");

}
