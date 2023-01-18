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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Request-Headers"),
                createString("X-PINGOTHER, Content-Type"));
    auto c = header->getAccessControlRequestHeaders();
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test SetToHeader case1]");
      break;
    }

    if(!list->get(1)->equals("Content-Type")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test SetToHeader case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Request-Headers"),
                createString("X-PINGOTHER"));
    auto c = header->getAccessControlRequestHeaders();
    auto list = c->get();
    if(!list->get(0)->equals("X-PINGOTHER")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestHeaders test SetToHeader case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestHeaders test SetToHeader case100]");
}
