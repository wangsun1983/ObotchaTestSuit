#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Accept"),
                createString("text/html"));
    auto encoding1 = header->getAccept();
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAccept test setToHeader case1]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("text/html")) {
        TEST_FAIL("[HttpHeaderAccept test setToHeader case2]");
        break;
    }
    break;
  }

  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Accept"),
                createString("image/*"));
    auto encoding1 = header->getAccept();
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAccept test setToHeader case3]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("image/*")) {
        TEST_FAIL("[HttpHeaderAccept test setToHeader case4]");
        break;
    }

    break;
  }

  while(1) {
    auto header = createHttpHeader();
    header->set(createString("Accept"),
                createString("text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8"));
    auto encoding1 = header->getAccept();
    auto encodings = encoding1->get();
    if(encodings->size() != 4) {
      TEST_FAIL("[HttpHeaderAccept test setToHeader case5]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("text/html")
      ||!encodings->get(1)->type->sameAs("application/xhtml+xml")
      ||!encodings->get(2)->type->sameAs("application/xml")
      ||!encodings->get(3)->type->sameAs("*/*")) {
        TEST_FAIL("[HttpHeaderAccept test setToHeader case6]");
        break;
    }

    if(st(Math)::compareFloat(encodings->get(2)->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAccept test setToHeader case5],weight is %f",encodings->get(2)->weight);
      break;
    }

    if(st(Math)::compareFloat(encodings->get(3)->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAccept test setToHeader case5],weight is %f",encodings->get(3)->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccept test setToHeader case100]");

}
