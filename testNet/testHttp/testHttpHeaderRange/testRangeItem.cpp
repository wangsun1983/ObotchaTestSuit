#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRange.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testRangeItem() {
  while(1) {
    HttpHeaderRangeItem item = createHttpHeaderRangeItem(1,2);
    if(item->rangeStart != 1 || item->rangeEnd != 2) {
        TEST_FAIL("[HttpHeaderRange test item case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderRange test item case100]");

}
