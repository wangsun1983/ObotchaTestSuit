#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderOrigin.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderOrigin match = createHttpHeaderOrigin();
    match->import("");
    
    if(!match->toString()->equals("")){
      TEST_FAIL("[HttpHeaderOrigin test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderOrigin match = createHttpHeaderOrigin();
    match->import("https://developer.mozilla.org:1234");
    if(!match->toString()->equals("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderOrigin test toString case2]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderOrigin test toString case100]");
}
