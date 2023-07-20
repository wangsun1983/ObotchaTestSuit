#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentRange.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange();
    range->load("bytes 200-1000/67589");
    if(!range->getUnit()->equals("bytes")) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case1]");
    }

    if(range->getStart() != 200) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case2]");
    }

    if(range->getEnd() != 1000) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case3]");
    }

    if(range->getSize() != 67589) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case4]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange(createString("bytes 200-1000/67589"));
    if(!range->getUnit()->equals("bytes")) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case5]");
    }

    if(range->getStart() != 200) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case6]");
    }

    if(range->getEnd() != 1000) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case7]");
    }

    if(range->getSize() != 67589) {
      TEST_FAIL("[HttpHeaderContentRange test Parse case8]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentRange test Parse case100]");

}
