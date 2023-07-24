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

void testGetSet() {
  
  while(1) {
    HttpHeaderContentRange range = createHttpHeaderContentRange();
    range->setUnit("bytes");
    range->setStart(200);
    range->setEnd(1000);
    range->setSize(67589);
    if(!range->toString()->sameAs("bytes 200-1000/67589")) {
      TEST_FAIL("[HttpHeaderContentRange testGetSet case1] range is %s",range->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentRange testGetSet case100]");

}
