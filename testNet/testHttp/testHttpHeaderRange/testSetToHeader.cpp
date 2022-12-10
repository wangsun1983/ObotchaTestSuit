#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRange.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Range"),createString("bytes=200-1000, 2000-6576, 19000-"));
    auto range = header->getRange();
    if(!range->getUnit()->equals("bytes")) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case1]");
      break;
    }

    auto list = range->getRanges();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case2]");
      break;
    }

    auto item0 = list->get(0);
    if(item0->start != 200) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case3],item0->start is %d",item0->start);
      break;
    }

    if(item0->end != 1000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case4]");
      break;
    }

    auto item1 = list->get(1);
    if(item1->start != 2000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case5]");
      break;
    }

    if(item1->end != 6576) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case6]");
      break;
    }

    auto item2 = list->get(2);
    if(item2->start != 19000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case7]");
      break;
    }

    if(item2->end != -1) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case8]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderRange test SetToHeader case100]");

}
