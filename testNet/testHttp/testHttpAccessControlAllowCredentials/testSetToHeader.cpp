#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowCredentials.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Credentials"),
                createString("true"));
    auto c = header->getAllowCredentials();
    
    if(!c->get()) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test SetToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Credentials"),
                createString("false"));
    auto c = header->getAllowCredentials();
    if(c->get()) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowCredentials test SetToHeader case100]");

}
