#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowHeaders.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Headers"),createString("X-Custom-Header, Upgrade-Insecure-Requests"));
    HttpHeaderAccessControlAllowHeaders c = header->getAllowHeaders();
    if(!c->toString()->equals("X-Custom-Header, Upgrade-Insecure-Requests")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test setToHeader case1] [FAILED] ,str is %s",c->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Headers"),createString("X-Custom-Header, Upgrade-Insecure-Requests"));
    HttpHeaderAccessControlAllowHeaders c = header->getAllowHeaders();
    c->import("*");
    if(!c->toString()->equals("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test setToHeader case1_1] [FAILED] ,str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Headers"),createString("*"));
    HttpHeaderAccessControlAllowHeaders c = header->getAllowHeaders();
    if(!c->toString()->equals("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowCredentials test setToHeader case100]");

}