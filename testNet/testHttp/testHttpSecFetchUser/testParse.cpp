#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchUser.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->load("?1");
    if(!save->get()->equals("?1")) {
      TEST_FAIL("[HttpHeaderSecFetchUser test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->load("?0");
    if(!save->get()->equals("?0")) {
      TEST_FAIL("[HttpHeaderSecFetchUser test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchUser test Parse case100]");

}
