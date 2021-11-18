#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentRange.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange();
    range->import("bytes 200-1000/67589");
    if(!range->toString()->equals("bytes 200-1000/67589")) {
      printf("---[HttpHeaderContentRange test toSring case1] [FAILED]--- range is %s\n",range->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderContentRange test toSring case100] [OK]--- \n");

}
