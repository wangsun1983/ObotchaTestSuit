#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentRange.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Content-Range"),
                createString("bytes 200-1000/67589"));
    auto range = header->getContentRange();
    if(!range->getUnit()->sameAs("bytes")) {
      TEST_FAIL("[HttpHeaderContentRange test SetToHeader case1]");
    }

    if(range->getStart() != 200) {
      TEST_FAIL("[HttpHeaderContentRange test SetToHeader case2]");
    }

    if(range->getEnd() != 1000) {
      TEST_FAIL("[HttpHeaderContentRange test SetToHeader case3]");
    }

    if(range->getSize() != 67589) {
      TEST_FAIL("[HttpHeaderContentRange test SetToHeader case4]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentRange test SetToHeader case100]");

}
