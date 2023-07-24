#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentRange.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange();
    range->load("bytes 200-1000/67589");
    if(!range->toString()->sameAs("bytes 200-1000/67589")) {
      TEST_FAIL("[HttpHeaderContentRange test toSring case1] range is %s",range->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderContentRange range_0 = createHttpHeaderContentRange();
    range_0->load("bytes 200-1000/67589");
    
    header->setContentRange(range_0);
    auto range = header->getContentRange();
    if(!range->toString()->sameAs("bytes 200-1000/67589")) {
      TEST_FAIL("[HttpHeaderContentRange test toSring case2] range is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentRange test toSring case100]");

}
