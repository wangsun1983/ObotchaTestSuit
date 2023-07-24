#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testContentTypeToString() {
  while(1) {
    HttpHeaderContentType contentType1 = createHttpHeaderContentType();
    contentType1->load("text/html;charset=utf-8");
    if(!contentType1->toString()->sameAs("text/html;charset=utf-8")) {
      TEST_FAIL("[HttpHeaderContentType test toString case1],type is %s",contentType1->toString()->toChars());
      return;
    }

    HttpHeaderContentType contentType2 = createHttpHeaderContentType();
    contentType2->load("multipart/form-data;boundary=something");
    if(!contentType2->toString()->sameAs("multipart/form-data;boundary=something")) {
      TEST_FAIL("[HttpHeaderContentType test toString case3],type is %s",contentType1->toString()->toChars());
      return;
    }
    break;
  }
  TEST_OK("[HttpHeaderContentType test toString case100]");

}
