#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderXFrameOptions.hpp"
#include "Math.hpp"

using namespace obotcha;

void testXFrameOptionsParse() {
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("deny");
    if(!options->option->equals("deny")) {
      printf("---[HttpHeaderXFrameOptions test Parse case1] [FAILED]---,option is %s \n",options->option->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("sameorigin");
    if(!options->option->equals("sameorigin")) {
      printf("---[HttpHeaderXFrameOptions test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->import("allow-from https://example.com/");
    if(!options->option->equals("allow-from")) {
      printf("---[HttpHeaderXFrameOptions test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!options->uri->equals("https://example.com/")) {
      printf("---[HttpHeaderXFrameOptions test Parse case4] [FAILED]---,uri is %s \n",options->uri->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderXFrameOptions test Parse case100] [OK]--- \n");

}
