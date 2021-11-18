#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderXFrameOptions.hpp"

using namespace obotcha;

void testXFrameOptionsToString() {
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("deny");
    if(!options->toString()->equals("deny")) {
      printf("---[HttpHeaderXFrameOptions test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("sameorigin");
    if(!options->toString()->equals("sameorigin")) {
      printf("---[HttpHeaderXFrameOptions test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("allow-from https://example.com/");
    if(!options->toString()->equals("allow-from https://example.com/")) {
      printf("---[HttpHeaderXFrameOptions test toString case3] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderXFrameOptions test toString case100] [OK]--- \n");

}
