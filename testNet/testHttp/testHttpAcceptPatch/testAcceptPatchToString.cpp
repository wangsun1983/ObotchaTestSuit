#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptPatch.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("application/example,text/example");
    if(!encoding1->toString()->equals("application/example,text/example")) {
      printf("---[HttpHeaderAcceptPatch test Parse case1] [FAILED]--- \n");
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("text/example;charset=utf-8");
    if(!encoding1->toString()->equals("text/example;charset=utf-8")) {
      printf("---[HttpHeaderAcceptPatch test Parse case2] [FAILED]--- \n");
    }

    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("application/merge-patch+json");
    if(!encoding1->toString()->equals("application/merge-patch+json")) {
      printf("---[HttpHeaderAcceptPatch test Parse case3] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderAcceptPatch test toString case100] [OK]--- \n");

}
