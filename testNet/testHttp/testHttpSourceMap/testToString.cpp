#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSourceMap timing = createHttpHeaderSourceMap();
    timing->import("/path/to/file.js.map");
    if(!timing->toString()->equals("/path/to/file.js.map")) {
      printf("---[HttpHeaderSourceMap test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderServerTiming test toString case100] [OK]--- \n");

}
