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

    if(!encodings->get(0)->type->sameAs("gzip")
      || !encodings->get(1)->type->sameAs("compress")
      || !encodings->get(2)->type->sameAs("br")) {
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

    if(!encodings->get(0)->type->sameAs("deflate")
      || !encodings->get(1)->type->sameAs("gzip")
      || !encodings->get(2)->type->sameAs("*")) {
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
  
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Encoding"),
                createString("deflate, gzip;q=1.0, *;q=0.5"));
                
    auto encoding1 = header->getAcceptEncoding();
    header->setAcceptEncoding(encoding1);
    encoding1 = header->getAcceptEncoding();
    
    auto encodings = encoding1->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case7]");
      break;
    }

    if(!encodings->get(0)->type->sameAs("deflate")
      || !encodings->get(1)->type->sameAs("gzip")
      || !encodings->get(2)->type->sameAs("*")) {
        TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case8]");
        break;
    }

    if(encodings->get(1)->weight != 1.0) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case9],weight is %f",encodings->get(1)->weight);
      break;
    }

    if(encodings->get(2)->weight != 0.5) {
      TEST_FAIL("[HttpHeaderAcceptEncoding test setToHeader case10],weight is %f",encodings->get(2)->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptEncoding test setToHeader case100]");

}
