#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("ON");
    if(!save->get()->equals("on")) {
      TEST_FAIL("[HttpHeaderSaveData test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->import("OFF");
    if(!save->get()->equals("off")) {
      TEST_FAIL("[HttpHeaderSaveData test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSaveData test Parse case100]");

}
