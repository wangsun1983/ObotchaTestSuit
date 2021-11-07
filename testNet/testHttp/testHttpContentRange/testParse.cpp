#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpContentRange.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpContentRange range = createHttpContentRange();
    range->import("bytes 200-1000/67589");
    if(!range->getUnit()->equals("bytes")) {
      printf("---[HttpContentRange test Parse case1] [FAILED]--- \n");
    }

    if(range->getStart() != 200) {
      printf("---[HttpContentRange test Parse case2] [FAILED]--- \n");
    }

    if(range->getEnd() != 1000) {
      printf("---[HttpContentRange test Parse case3] [FAILED]--- \n");
    }

    if(range->getSize() != 67589) {
      printf("---[HttpContentRange test Parse case4] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpContentRange test Parse case100] [OK]--- \n");

}
