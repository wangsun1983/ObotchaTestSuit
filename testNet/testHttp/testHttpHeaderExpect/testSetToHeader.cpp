#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void setToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    //HttpHeaderExpect expect = createHttpHeaderExpect();
    header->set(createString("Expect"),createString("100-continue"));
    auto expect = header->getExpect();
    auto str = expect->get();
    if(!str->sameAs("100-continue")) {
      TEST_FAIL("[HttpHeaderExpect test setToHeader case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderExpect test setToHeader case100]");

}
