#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderContentLength.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Content-Length"),createString(" 123 "));
    if(header->getContentLength()->get() != 123) {
      TEST_FAIL("[testSetToHeader test Parse case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    auto contentLength = createHttpHeaderContentLength();
    contentLength->set(123);
    header->setContentLength(contentLength);
    if(header->getContentLength()->get() != 123) {
      TEST_FAIL("[testSetToHeader test Parse case2]");
    }
    break;
  }

  TEST_OK("[testSetToHeader test Parse case100]");
}
