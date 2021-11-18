#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"

using namespace obotcha;

void testContentTypeParse() {
  while(1) {
    HttpHeaderContentType contentType1 = createHttpHeaderContentType();
    contentType1->import("text/html; charset=utf-8");
    if(!contentType1->getType()->equals("text/html")) {
      printf("---[HttpHeaderContentType test Parse case1] [FAILED]---,type is %s \n",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->equals("utf-8")) {
      printf("---[HttpHeaderContentType test Parse case2] [FAILED]---,value is %s \n",contentType1->getCharSet()->toChars());
    }

    HttpHeaderContentType contentType2 = createHttpHeaderContentType();
    contentType2->import("multipart/form-data; boundary=something");
    if(!contentType2->getType()->equals("multipart/form-data")) {
      printf("---[HttpHeaderContentType test Parse case3] [FAILED]---,type is %s \n",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->equals("something")) {
      printf("---[HttpHeaderContentType test Parse case4] [FAILED]---,value is %s \n",contentType1->getBoundary()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderContentType contentType1 = createHttpHeaderContentType();
    contentType1->import("text/html; charset = utf-8 ");
    if(!contentType1->getType()->equals("text/html")) {
      printf("---[HttpHeaderContentType test Parse case5] [FAILED]---,type is %s \n",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->equals("utf-8")) {
      printf("---[HttpHeaderContentType test Parse case6] [FAILED]---,value is %s \n",contentType1->getCharSet()->toChars());
    }

    HttpHeaderContentType contentType2 = createHttpHeaderContentType();
    contentType2->import("multipart/form-data; boundary = something");
    if(!contentType2->getType()->equals("multipart/form-data")) {
      printf("---[HttpHeaderContentType test Parse case7] [FAILED]---,type is %s \n",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->equals("something")) {
      printf("---[HttpHeaderContentType test Parse case8] [FAILED]---,value is %s \n",contentType1->getBoundary()->toChars());
    }
    break;
  }

  printf("---[HttpHeaderContentType test Parse case100] [OK]--- \n");

}
