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
    HttpHeaderAccessControlRequestHeaders c = HttpHeaderAccessControlRequestHeaders::New();
    c->load("X-PINGOTHER, Content-Type");
    if(!c->toString()->sameAs("X-PINGOTHER, Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = HttpHeaderAccessControlRequestHeaders::New();
    c->load("X-PINGOTHER");
    if(!c->toString()->sameAs("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case3]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = HttpHeaderAccessControlRequestHeaders::New();
    c->add(String::New("X-PINGOTHER"));
    c->add(String::New("Content-Type"));
    if(!c->toString()->sameAs("X-PINGOTHER, Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test toString case4]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestHeaders test toString case100]");

}
