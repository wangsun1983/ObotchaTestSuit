#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchDest.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->load("audio");
    if(!save->get()->equals("audio")) {
      TEST_FAIL("[HttpHeaderSecFetchDest test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->load("track");
    if(!save->get()->equals("track")) {
      TEST_FAIL("[HttpHeaderSecFetchDest test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchDest test Parse case100]");

}
