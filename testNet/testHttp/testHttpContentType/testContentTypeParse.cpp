#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testContentTypeParse() {
  while(1) {
    HttpHeaderContentType contentType1 = HttpHeaderContentType::New();
    contentType1->load("text/html; charset=utf-8");
    if(!contentType1->getType()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case1],type is %s",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->sameAs("utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case2],value is %s",contentType1->getCharSet()->toChars());
    }

    HttpHeaderContentType contentType2 = HttpHeaderContentType::New();
    contentType2->load("multipart/form-data; boundary=something");
    if(!contentType2->getType()->sameAs("multipart/form-data")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case3],type is %s",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->sameAs("something")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case4],value is %s",contentType1->getBoundary()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderContentType contentType1 = HttpHeaderContentType::New();
    contentType1->load("text/html; charset = utf-8 ");
    if(!contentType1->getType()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case5],type is %s",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->sameAs("utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case6],value is %s",contentType1->getCharSet()->toChars());
    }

    HttpHeaderContentType contentType2 = HttpHeaderContentType::New();
    contentType2->load("multipart/form-data; boundary = something");
    if(!contentType2->getType()->sameAs("multipart/form-data")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case7],type is %s",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->sameAs("something")) {
      TEST_FAIL("[HttpHeaderContentType test Parse case8],value is %s",contentType1->getBoundary()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderContentType test Parse case100]");

}
