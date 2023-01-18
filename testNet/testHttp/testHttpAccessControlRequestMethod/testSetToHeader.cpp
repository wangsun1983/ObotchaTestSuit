#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlRequestMethod.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Request-Method"),createString("POST"));
    auto c = header->getAccessControlRequestMethod();
    if(c->get() != st(HttpMethod)::Post){
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test setToHeader case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderAccessControlRequestMethod meth = createHttpHeaderAccessControlRequestMethod();
    meth->import("POST");
    header->setAccessControlRequestMethod(meth);
    auto c = header->getAccessControlRequestMethod();
    if(c->get() != st(HttpMethod)::Post){
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestMethod test setToHeader case100]");

}
