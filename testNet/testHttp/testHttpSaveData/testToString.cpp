#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->load("ON");
    if(!save->toString()->sameAs("on")) {
      TEST_FAIL("[HttpHeaderSaveData test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->load("OFF");
    if(!save->toString()->sameAs("off")) {
      TEST_FAIL("[HttpHeaderSaveData test toString case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderSaveData save = createHttpHeaderSaveData();
    save->load("OFF");
    HttpHeader header = createHttpHeader();
    header->setSaveData(save);
    
    auto save2 = header->getSaveData();
    if(!save2->toString()->sameAs("off")) {
      TEST_FAIL("[HttpHeaderSaveData test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSaveData test toString case100]");

}
