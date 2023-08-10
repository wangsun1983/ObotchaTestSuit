#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchDest.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSet() {
  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->set(" track ");
    if(!save->toString()->sameAs("track")) {
      TEST_FAIL("[HttpHeaderSecFetchDest set test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->set(" audio ");
    if(!save->toString()->sameAs("audio")) {
      TEST_FAIL("[HttpHeaderSecFetchDest set test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchDest test toString case100]");

}
