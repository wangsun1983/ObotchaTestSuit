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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->load("true");
    if(!c->get()) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlAllowCredentials c = createHttpHeaderAccessControlAllowCredentials();
    c->load("false");
    if(c->get()) {
      TEST_FAIL("[HttpHeaderAccessControlAllowCredentials test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowCredentials test Parse case100]");

}
