#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("ON");
    if(!save->get()->equals("on")) {
      printf("---[HttpHeaderSaveData test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("OFF");
    if(!save->get()->equals("off")) {
      printf("---[HttpHeaderSaveData test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSaveData test Parse case100] [OK]--- \n");

}
