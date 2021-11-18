#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("ON");
    if(!save->toString()->equals("on")) {
      printf("---[HttpHeaderSaveData test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("OFF");
    if(!save->toString()->equals("off")) {
      printf("---[HttpHeaderSaveData test toString case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSaveData test toString case100] [OK]--- \n");

}
