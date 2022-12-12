#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlExposeHeaders.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Expose-Headers"),
                createString("Content-Length, X-Kuma-Revision"));
    auto c = header->getExposeHeaders();
    
    auto list = c->get();
    String v0 = list->get(0);
    if(!v0->equals("Content-Length")) {
      TEST_FAIL("[HttpHeaderAccessControlExposeHeaders test setToHeader case1]");
      break;
    }

    String v1 = list->get(1);
    if(!v1->equals("X-Kuma-Revision")) {
      TEST_FAIL("[HttpHeaderAccessControlExposeHeaders test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlExposeHeaders test setToHeader case100]");

}
