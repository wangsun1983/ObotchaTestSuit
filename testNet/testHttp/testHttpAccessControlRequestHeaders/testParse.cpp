#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlRequestHeaders.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlRequestHeaders c = HttpHeaderAccessControlRequestHeaders::New();
    c->load("X-PINGOTHER, Content-Type");
    auto list = c->get();
    if(!list->get(0)->sameAs("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case1]");
      break;
    }

    if(!list->get(1)->sameAs("Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = HttpHeaderAccessControlRequestHeaders::New();
    c->load("X-PINGOTHER");
    auto list = c->get();
    if(!list->get(0)->sameAs("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestHeaders test Parse case100]");
}
