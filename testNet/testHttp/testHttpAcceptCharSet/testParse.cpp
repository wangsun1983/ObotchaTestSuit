#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "Math.hpp"

using namespace obotcha;

void testCharSetParse() {
  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("iso-8859-1");
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 1) {
      printf("---[HttpHeaderAcceptCharSet test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!charsets->get(0)->type->equals("iso-8859-1")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case2] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("utf-8, iso-8859-1;q=0.5");
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 2) {
      printf("---[HttpHeaderAcceptCharSet test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!charsets->get(0)->type->equals("utf-8")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case4] [FAILED]--- \n");
        break;
    }

    if(!charsets->get(1)->type->equals("iso-8859-1")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case5] [FAILED]--- \n");
        break;
    }

    if(charsets->get(1)->weight != 0.5) {
        printf("---[HttpHeaderAcceptCharSet test Parse case6] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("utf-8, iso-8859-1;q=0.5, *;q=0.1");
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 3) {
      printf("---[HttpHeaderAcceptCharSet test Parse case7] [FAILED]--- \n");
      break;
    }

    if(!charsets->get(0)->type->equals("utf-8")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case8] [FAILED]--- \n");
        break;
    }

    if(!charsets->get(1)->type->equals("iso-8859-1")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case9] [FAILED]--- \n");
        break;
    }

    if(charsets->get(1)->weight != 0.5) {
        printf("---[HttpHeaderAcceptCharSet test Parse case10] [FAILED]--- \n");
        break;
    }

    if(!charsets->get(2)->type->equals("*")) {
        printf("---[HttpHeaderAcceptCharSet test Parse case11] [FAILED]--- \n");
        break;
    }

    if(st(Math)::compareFloat(charsets->get(2)->weight,0.1) != st(Math)::AlmostEqual) {
        printf("---[HttpHeaderAcceptCharSet test Parse case12] [FAILED]---,weight is %f \n",charsets->get(2)->weight);
        break;
    }
    break;
  }

  printf("---[HttpHeaderAcceptCharSet test Parse case100] [OK]--- \n");

}
