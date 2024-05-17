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
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Access-Control-Request-Method"),String::New("POST"));
    auto c = header->getAccessControlRequestMethod();
    if(c->get() != st(HttpMethod)::Id::Post){
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test setToHeader case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderAccessControlRequestMethod meth = HttpHeaderAccessControlRequestMethod::New();
    meth->load("POST");
    header->setAccessControlRequestMethod(meth);
    auto c = header->getAccessControlRequestMethod();
    if(c->get() != st(HttpMethod)::Id::Post){
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestMethod test setToHeader case100]");

}
