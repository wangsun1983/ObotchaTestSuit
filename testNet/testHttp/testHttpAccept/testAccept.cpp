#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void testEncodingParse() {
  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("text/html");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAccept test Parse case1]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("text/html")) {
        TEST_FAIL("[HttpHeaderAccept test Parse case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("image/*");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAccept test Parse case3]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("image/*")) {
        TEST_FAIL("[HttpHeaderAccept test Parse case4]");
        break;
    }

    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8");
    auto encodings = encoding1->get();
    if(encodings->size() != 4) {
      TEST_FAIL("[HttpHeaderAccept test Parse case5]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("text/html")
      ||!encodings->get(1)->type->sameAs("application/xhtml+xml")
      ||!encodings->get(2)->type->sameAs("application/xml")
      ||!encodings->get(3)->type->sameAs("*/*")) {
        TEST_FAIL("[HttpHeaderAccept test Parse case6]");
        break;
    }

    if(st(Math)::compareFloat(encodings->get(2)->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAccept test Parse case5],weight is %f",encodings->get(2)->weight);
      break;
    }

    if(st(Math)::compareFloat(encodings->get(3)->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAccept test Parse case5],weight is %f",encodings->get(3)->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccept test Parse case100]");

}
