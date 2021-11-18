#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchMode.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("navigate");
    if(!save->toString()->equals("navigate")) {
      printf("---[HttpHeaderSecFetchMode test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("nested-navigate");
    if(!save->toString()->equals("nested-navigate")) {
      printf("---[HttpHeaderSecFetchMode test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecFetchMode test toString case100] [OK]--- \n");

}
