#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Ranges"),
                createString("bytes"));
    //HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    //ranges->import("bytes");
    auto ranges = header->getAcceptRanges();
    if(!ranges->get()->equals("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Ranges"),
                createString("none"));
    //HttpHeaderAcceptRanges ranges = createHttpHeaderAcceptRanges();
    //ranges->import("bytes");
    auto ranges = header->getAcceptRanges();

    if(!ranges->get()->equals("none")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case2]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptRanges test Parse case100]");

}
