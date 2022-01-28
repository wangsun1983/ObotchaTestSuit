#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpCookieParser.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCookieParse() {
  while(1) {
    String cookie = "yummy_cookie=choco; tasty_cookie=strawberry";
    ArrayList<HttpCookie> cookies = st(HttpCookieParser)::parse(cookie);
    if(cookies == nullptr || cookies->size() != 2) {
      TEST_FAIL("[HttpCookie test Parse case1]");
      break;
    }

    auto cookie1 = cookies->get(0);
    if(!cookie1->getName()->equals("yummy_cookie") || !cookie1->getValue()->equals("choco")) {
      TEST_FAIL("[HttpCookie test Parse case2]");
      break;
    }

    auto cookie2 = cookies->get(1);
    if(!cookie2->getName()->equals("tasty_cookie") || !cookie2->getValue()->equals("strawberry")) {
      TEST_FAIL("[HttpCookie test Parse case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpCookie test Parse case100]");

}
