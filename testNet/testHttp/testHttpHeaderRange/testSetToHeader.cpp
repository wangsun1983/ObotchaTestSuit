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
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Range"),String::New("bytes=200-1000, 2000-6576, 19000-"));
    auto range = header->getRange();
    if(!range->getUnit()->sameAs("bytes")) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case1]");
      break;
    }

    auto list = range->getRanges();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case2]");
      break;
    }

    auto item0 = list->get(0);
    if(item0->rangeStart != 200) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case3],item0->rangeStart is %d",item0->rangeStart);
      break;
    }

    if(item0->rangeEnd != 1000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case4]");
      break;
    }

    auto item1 = list->get(1);
    if(item1->rangeStart != 2000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case5]");
      break;
    }

    if(item1->rangeEnd != 6576) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case6]");
      break;
    }

    auto item2 = list->get(2);
    if(item2->rangeStart != 19000) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case7]");
      break;
    }

    if(item2->rangeEnd != -1) {
      TEST_FAIL("[HttpHeaderRange test SetToHeader case8]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderRange test SetToHeader case100]");

}
