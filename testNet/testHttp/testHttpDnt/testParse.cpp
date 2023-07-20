#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->load("1");
    int val = dnt->get();
    if(val != 1) {
      TEST_FAIL("[HttpHeaderDnt test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->load("0");
    int val = dnt->get();
    if(val != 0) {
      TEST_FAIL("[HttpHeaderDnt test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderDnt test Parse case100]");

}
