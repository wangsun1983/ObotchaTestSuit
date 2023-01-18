#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlExposeHeaders.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlExposeHeaders c = createHttpHeaderAccessControlExposeHeaders();
    c->import("Content-Length, X-Kuma-Revision");
    if(c->toString()->equals("Content-Length, X-Kuma-Revision")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccessControlExposeHeaders c = createHttpHeaderAccessControlExposeHeaders();
    c->import("Content-Length, X-Kuma-Revision");
    HttpHeader header = createHttpHeader();
    header->setExposeHeaders(c);
    
    auto c2 = header->getExposeHeaders();
    if(c2->toString()->equals("Content-Length, X-Kuma-Revision")) {
      TEST_FAIL("[HttpHeaderAccessControlAllowOrigin test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlAllowOrigin test toString case100]");

}
