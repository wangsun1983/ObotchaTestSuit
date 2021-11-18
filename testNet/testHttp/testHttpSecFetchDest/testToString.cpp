#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchDest.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->import("track");
    if(!save->toString()->equals("track")) {
      printf("---[HttpHeaderSecFetchDest test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchDest save = createHttpHeaderSecFetchDest();
    save->import("audio");
    if(!save->toString()->equals("audio")) {
      printf("---[HttpHeaderSecFetchDest test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecFetchDest test toString case100] [OK]--- \n");

}
