#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("ON");
    if(!save->toString()->equals("on")) {
      TEST_FAIL("[HttpHeaderSaveData test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("OFF");
    if(!save->toString()->equals("off")) {
      TEST_FAIL("[HttpHeaderSaveData test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSaveData test toString case100]");

}
