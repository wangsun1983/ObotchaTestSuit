#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptEncoding.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testEncodingToString() {
  while(1) {
    HttpHeaderAcceptEncoding encoding1 = HttpHeaderAcceptEncoding::New();
    encoding1->load("gzip,compress,br");
    if(!encoding1->toString()->sameAs("gzip,compress,br")) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test toString case1] [FAILED] encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptEncoding encoding1 = HttpHeaderAcceptEncoding::New();
    encoding1->load("deflate,gzip;q=0.2,*;q=0.5");
    //q default value is 1,no need
    if(!encoding1->toString()->sameAs("deflate,gzip;q=0.2,*;q=0.5")) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test toString case2] [FAILED] encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptEncoding test toString case100]");
}
