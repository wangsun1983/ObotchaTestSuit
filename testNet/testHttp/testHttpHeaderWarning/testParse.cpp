#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderWarning warning = createHttpHeaderWarning();
    warning->import("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"");
    if(warning->getCode() != 112) {
      printf("---[HttpHeaderWarning test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!warning->getAgent()->equals("-")) {
      printf("---[HttpHeaderWarning test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!warning->getText()->equals("cache down")) {
      printf("---[HttpHeaderWarning test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!warning->getDateTime()->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpHeaderWarning test Parse case4] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderWarning warning = createHttpHeaderWarning();
    warning->import("110 anderson/1.3.37 \"Response is stale\"");
    if(warning->getCode() != 110) {
      printf("---[HttpHeaderWarning test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!warning->getAgent()->equals("anderson/1.3.37")) {
      printf("---[HttpHeaderWarning test Parse case6] [FAILED]--- \n");
      break;
    }

    if(!warning->getText()->equals("Response is stale")) {
      printf("---[HttpHeaderWarning test Parse case7] [FAILED]--- \n");
      break;
    }

    if(warning->getDateTime() != nullptr) {
      printf("---[HttpHeaderWarning test Parse case8] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderWarning test Parse case100] [OK]--- \n");
}
