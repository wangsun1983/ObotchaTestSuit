#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSaveData.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Save-Data"),
                String::New("ON"));
    auto save = header->getSaveData();
    if(!save->get()->sameAs("on")) {
      TEST_FAIL("[HttpHeaderSaveData test SetToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Save-Data"),
                String::New("OFF"));
    auto save = header->getSaveData();
    if(!save->get()->sameAs("off")) {
      TEST_FAIL("[HttpHeaderSaveData test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSaveData test SetToHeader case100]");

}
