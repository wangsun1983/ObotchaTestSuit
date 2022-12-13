#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptEncoding.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Encoding"),
                createString("gzip, compress, br"));
                
    auto encoding1 = header->getAcceptEncoding();
    auto encodings = encoding1->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case1]");
      break;
    }

    if(!encodings->get(0)->type->equals("gzip")
      || !encodings->get(1)->type->equals("compress")
      || !encodings->get(2)->type->equals("br")) {
        TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Encoding"),
                createString("deflate, gzip;q=1.0, *;q=0.5"));
                
    auto encoding1 = header->getAcceptEncoding();
    auto encodings = encoding1->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case3]");
      break;
    }

    if(!encodings->get(0)->type->equals("deflate")
      || !encodings->get(1)->type->equals("gzip")
      || !encodings->get(2)->type->equals("*")) {
        TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case4]");
        break;
    }

    if(encodings->get(1)->weight != 1.0) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case5],weight is %f",encodings->get(1)->weight);
      break;
    }

    if(encodings->get(2)->weight != 0.5) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case6],weight is %f",encodings->get(2)->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptEncoding test setToHeader case100]");

}
