#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlRequestHeaders.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->load("X-PINGOTHER, Content-Type");
    if(!c->toString()->sameAs("X-PINGOTHER, Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->load("X-PINGOTHER");
    if(!c->toString()->sameAs("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case3]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->add(createString("X-PINGOTHER"));
    c->add(createString("Content-Type"));
    if(!c->toString()->sameAs("X-PINGOTHER, Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case4]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestHeaders test toString case100]");

}
