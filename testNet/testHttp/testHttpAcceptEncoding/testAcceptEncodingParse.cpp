#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptEncoding.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testEncodingParse() {
  while(1) {
    HttpHeaderAcceptEncoding encoding1 = HttpHeaderAcceptEncoding::New();
    encoding1->load("gzip, compress, br");
    auto encodings = encoding1->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case1]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("gzip")
      || !encodings->get(1)->type->sameAs("compress")
      || !encodings->get(2)->type->sameAs("br")) {
        TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptEncoding encoding1 = HttpHeaderAcceptEncoding::New();
    encoding1->load("deflate, gzip;q=1.0, *;q=0.5");
    auto encodings = encoding1->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case3]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("deflate")
      || !encodings->get(1)->type->sameAs("gzip")
      || !encodings->get(2)->type->sameAs("*")) {
        TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case4]");
        break;
    }

    if(encodings->get(1)->weight != 1.0) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case5],weight is %f",encodings->get(1)->weight);
      break;
    }

    if(encodings->get(2)->weight != 0.5) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test Parse case6],weight is %f",encodings->get(2)->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptEncoding test Parse case100]");

}
