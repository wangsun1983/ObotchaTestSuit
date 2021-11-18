#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->import("1");
    int val = dnt->get();
    if(val != 1) {
      printf("---[HttpHeaderDnt test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->import("0");
    int val = dnt->get();
    if(val != 0) {
      printf("---[HttpHeaderDnt test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderDnt test Parse case100] [OK]--- \n");

}
