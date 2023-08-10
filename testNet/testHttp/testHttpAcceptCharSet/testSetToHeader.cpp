#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Charset"),
                createString("iso-8859-1"));
    auto charset = header->getAcceptCharSet();
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 1) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case1]");
      break;
    }

    if(!charsets->get(0)->type->sameAs("iso-8859-1")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Charset"),
                createString("utf-8, iso-8859-1;q=0.5"));
    auto charset = header->getAcceptCharSet();
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 2) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case3]");
      break;
    }

    if(!charsets->get(0)->type->sameAs("utf-8")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case4]");
        break;
    }

    if(!charsets->get(1)->type->sameAs("iso-8859-1")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case5]");
        break;
    }

    if(charsets->get(1)->weight != 0.5) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case6]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Charset"),
                createString("utf-8, iso-8859-1;q=0.5, *;q=0.1"));
    auto charset = header->getAcceptCharSet();
    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 3) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case7]");
      break;
    }

    if(!charsets->get(0)->type->sameAs("utf-8")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case8]");
        break;
    }

    if(!charsets->get(1)->type->sameAs("iso-8859-1")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case9]");
        break;
    }

    if(charsets->get(1)->weight != 0.5) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case10]");
        break;
    }

    if(!charsets->get(2)->type->sameAs("*")) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case11]");
        break;
    }

    if(st(Math)::compareFloat(charsets->get(2)->weight,0.1) != st(Math)::AlmostEqual) {
        TEST_FAIL("[HttpHeaderAcceptCharSet test setToHeader case12],weight is %f",charsets->get(2)->weight);
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCharSet test setToHeader case100]");

}
