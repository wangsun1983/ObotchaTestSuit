#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Content-Type"),
                createString("text/html; charset=utf-8"));
    auto contentType1 = header->getContentType();
    if(!contentType1->getType()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case1],type is %s",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->sameAs("utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case2],value is %s",contentType1->getCharSet()->toChars());
    }
    
    header->set(createString("Content-Type"),
                createString("multipart/form-data; boundary=something"));
    auto contentType2 = header->getContentType();
    if(!contentType2->getType()->sameAs("multipart/form-data")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case3],type is %s",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->sameAs("something")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case4],value is %s",contentType1->getBoundary()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Content-Type"),
                createString("text/html; charset = utf-8 "));
                
    auto contentType1 = header->getContentType();
    if(!contentType1->getType()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case5],type is %s",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->sameAs("utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case6],value is %s",contentType1->getCharSet()->toChars());
    }
    
    header->set(createString("Content-Type"),
                createString("multipart/form-data; boundary = something"));
    auto contentType2 = header->getContentType();
    if(!contentType2->getType()->sameAs("multipart/form-data")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case7],type is %s",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->sameAs("something")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case8],value is %s",contentType1->getBoundary()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Content-Type"),
                createString("text/html; charset = utf-8 "));
                
    auto contentType1 = header->getContentType();
    header->setContentType(contentType1);
    
    contentType1 = header->getContentType();
    if(!contentType1->getType()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case9],type is %s",contentType1->getType()->toChars());
      return;
    }

    if(!contentType1->getCharSet()->sameAs("utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case10],value is %s",contentType1->getCharSet()->toChars());
    }
    
    header->set(createString("Content-Type"),
                createString("multipart/form-data; boundary = something"));
    auto contentType2 = header->getContentType();
    if(!contentType2->getType()->sameAs("multipart/form-data")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case11],type is %s",contentType2->getType()->toChars());
      return;
    }

    if(!contentType2->getBoundary()->sameAs("something")) {
      TEST_FAIL("[HttpHeaderContentType test SetToHeader case12],value is %s",contentType1->getBoundary()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderContentType test SetToHeader case100]");

}
