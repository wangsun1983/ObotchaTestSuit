#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderWarning warning = createHttpHeaderWarning();
  warning->import("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"");
  if(!warning->toString()->equals("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\"")) {
    printf("---[HttpHeaderWarning test toString case1] [FAILED]---,warn is %s \n",warning->toString()->toChars());
    return;
  }

  warning = createHttpHeaderWarning();
  warning->import("110 anderson/1.3.37 \"Response is stale\"");
  if(!warning->toString()->equals("110 anderson/1.3.37 \"Response is stale\"")) {
    printf("---[HttpHeaderWarning test toString case2] [FAILED]--- warn is %s \n",warning->toString()->toChars());
    return;
  }
  printf("---[HttpHeaderWarning test toString case100] [OK]--- \n");
}
