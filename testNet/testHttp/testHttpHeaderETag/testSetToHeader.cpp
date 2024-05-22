#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeader.hpp"
#include "TestLog.hpp"
#include "HttpHeaderETag.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = HttpHeader::New();
    header->set(String::New("etag"),
                String::New("\"33a64df551425fcc55e4d42a148795d9f25f89d4\""));
    auto p = header->getETag();
    
    if(p->isWeakCheck()) {
      TEST_FAIL("[HttpHeaderETag test setToHeader case1]");
    }

    if(!p->getValue()->sameAs("33a64df551425fcc55e4d42a148795d9f25f89d4")) {
      TEST_FAIL("[HttpHeaderETag test setToHeader case2]");
    }
    break;
  }

  while(1) {
    auto header = HttpHeader::New();
    header->set(String::New("etag"),
                String::New("W/\"0815\""));
    auto p = header->getETag();
    
    if(!p->isWeakCheck()) {
      TEST_FAIL("[HttpHeaderETag test setToHeader case3]");
    }

    if(!p->getValue()->sameAs("0815")) {
      TEST_FAIL("[HttpHeaderETag test setToHeader case4]");
    }
    break;
  }

  TEST_OK("[HttpHeaderXXssProtection test setToHeader case100]");

}
