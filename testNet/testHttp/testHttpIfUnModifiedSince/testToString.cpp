#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfUnmodifiedSince.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpHeaderIfUnmodifiedSince modifiedSince = createHttpHeaderIfUnmodifiedSince();
    modifiedSince->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!modifiedSince->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpHeaderIfUnmodifiedSince test toString case1] [FAILED]--- date is %s\n",modifiedSince->toString()->toChars());
    }
    break;
  }

  printf("---[HttpHeaderIfUnmodifiedSince test toString case100] [OK]--- \n");

}
