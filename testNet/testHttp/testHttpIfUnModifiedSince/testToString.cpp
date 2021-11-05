#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpIfUnmodifiedSince.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpIfUnmodifiedSince modifiedSince = createHttpIfUnmodifiedSince();
    modifiedSince->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!modifiedSince->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpIfUnmodifiedSince test toString case1] [FAILED]--- date is %s\n",modifiedSince->toString()->toChars());
    }
    break;
  }

  printf("---[HttpIfUnmodifiedSince test toString case100] [OK]--- \n");

}
