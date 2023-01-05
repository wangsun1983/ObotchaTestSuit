#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderFrom.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("From"),createString(" webmaster@example.org"));
    auto digest = header->getFrom();
    if(!digest->toString()->equals("webmaster@example.org")) {
      TEST_FAIL("[HttpHeaderFrom test setToHeader case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderFrom test setToHeader case100]");
}
