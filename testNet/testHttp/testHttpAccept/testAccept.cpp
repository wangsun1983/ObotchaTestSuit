#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"

using namespace obotcha;

void testEncodingParse() {
  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("text/html");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      printf("---[HttpHeaderAccept test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!encodings->get(0)->type->equals("text/html")) {
        printf("---[HttpHeaderAccept test Parse case2] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("image/*");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      printf("---[HttpHeaderAccept test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!encodings->get(0)->type->equals("image/*")) {
        printf("---[HttpHeaderAccept test Parse case4] [FAILED]--- \n");
        break;
    }

    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8");
    auto encodings = encoding1->get();
    if(encodings->size() != 4) {
      printf("---[HttpHeaderAccept test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!encodings->get(0)->type->equals("text/html")
      ||!encodings->get(1)->type->equals("application/xhtml+xml")
      ||!encodings->get(2)->type->equals("application/xml")
      ||!encodings->get(3)->type->equals("*/*")) {
        printf("---[HttpHeaderAccept test Parse case6] [FAILED]--- \n");
        break;
    }

    if(st(Math)::compareFloat(encodings->get(2)->weight,0.9) != st(Math)::AlmostEqual) {
      printf("---[HttpHeaderAccept test Parse case5] [FAILED]--- ,weight is %f\n",encodings->get(2)->weight);
      break;
    }

    if(st(Math)::compareFloat(encodings->get(3)->weight,0.8) != st(Math)::AlmostEqual) {
      printf("---[HttpHeaderAccept test Parse case5] [FAILED]--- ,weight is %f\n",encodings->get(3)->weight);
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccept test Parse case100] [OK]--- \n");

}
