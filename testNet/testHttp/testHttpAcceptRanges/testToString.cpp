#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAcceptRanges ranges = HttpHeaderAcceptRanges::New();
    ranges->load("none");

    if(!ranges->toString()->sameAs("none")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test toString case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptRanges ranges = HttpHeaderAcceptRanges::New();
    ranges->load("bytes");

    if(!ranges->toString()->sameAs("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test toString case2]");
        break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptRanges ranges = HttpHeaderAcceptRanges::New();
    ranges->set("bytes");

    if(!ranges->toString()->sameAs("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test toString case3]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccept test toString case100]");

}
