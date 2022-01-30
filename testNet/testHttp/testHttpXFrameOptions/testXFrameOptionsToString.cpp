#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderXFrameOptions.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testXFrameOptionsToString() {
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("deny");
    if(!options->toString()->equals("deny")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("sameorigin");
    if(!options->toString()->equals("sameorigin")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("allow-from https://example.com/");
    if(!options->toString()->equals("allow-from https://example.com/")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case3]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderXFrameOptions test toString case100]");

}
