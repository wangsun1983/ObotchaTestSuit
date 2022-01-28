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
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER, Content-Type");
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case1]");
      break;
    }

    if(!list->get(1)->equals("Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAccessControlRequestHeaders c = createHttpHeaderAccessControlRequestHeaders();
    c->import("X-PINGOTHER");
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test Parse case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestHeaders test Parse case100]");
}
