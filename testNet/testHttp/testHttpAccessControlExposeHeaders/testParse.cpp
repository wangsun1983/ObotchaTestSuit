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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlExposeHeaders c = createHttpHeaderAccessControlExposeHeaders();
    c->import("Content-Length, X-Kuma-Revision");
    auto list = c->get();
    String v0 = list->get(0);
    if(!v0->equals("Content-Length")) {
      TEST_FAIL("[HttpHeaderAccessControlExposeHeaders test Parse case1]");
      break;
    }

    String v1 = list->get(1);
    if(!v1->equals("X-Kuma-Revision")) {
      TEST_FAIL("[HttpHeaderAccessControlExposeHeaders test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlExposeHeaders test Parse case100]");

}
