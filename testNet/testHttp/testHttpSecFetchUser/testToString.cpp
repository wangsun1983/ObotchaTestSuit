#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchUser.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->import("navigate");
    if(!save->toString()->equals("navigate")) {
      printf("---[HttpHeaderSecFetchUser test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->import("nested-navigate");
    if(!save->toString()->equals("nested-navigate")) {
      printf("---[HttpHeaderSecFetchUser test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecFetchUser test toString case100] [OK]--- \n");

}
