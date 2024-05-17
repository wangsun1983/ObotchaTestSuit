#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowOrigin.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Access-Control-Allow-Origin"),
                String::New("https://developer.mozilla.org"));
    auto c = header->getAllowOrigin();
    if(!c->get()->sameAs("https://developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test setToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Access-Control-Allow-Origin"),
                String::New("*"));
    auto c = header->getAllowOrigin();
    if(!c->get()->sameAs("*")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test setToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowOrigin test setToHeader case100]");

}
