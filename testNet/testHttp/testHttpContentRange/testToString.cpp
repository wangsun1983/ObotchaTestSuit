#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentRange.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange();
    range->import("bytes 200-1000/67589");
    if(!range->toString()->equals("bytes 200-1000/67589")) {
      TEST_FAIL("[HttpHeaderContentRange test toSring case1] range is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentRange test toSring case100]");

}
