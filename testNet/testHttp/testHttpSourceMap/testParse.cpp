#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSourceMap timing = createHttpHeaderSourceMap();
    timing->import("/path/to/file.js.map");
    if(!timing->get()->equals("/path/to/file.js.map")) {
      printf("---[HttpHeaderSourceMap test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSourceMap test Parse case100] [OK]--- \n");

}
