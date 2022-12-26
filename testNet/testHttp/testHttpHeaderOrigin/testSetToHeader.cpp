#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderOrigin.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "NetProtocol.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Origin"),createString(""));
    auto match = header->getOrigin();
    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderOrigin test setToHeader case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Origin"),createString("https://developer.mozilla.org:1234"));
    auto match = header->getOrigin();
    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderOrigin test setToHeader case2]");
      break;
    }

    if(url->getScheme() != st(NetProtocol)::Https) {
      TEST_FAIL("[HttpHeaderOrigin test setToHeader case3]");
      break;
    }

    if(!url->getHost()->equals("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderOrigin test setToHeader case4]");
      break;
    }

    if(url->getPort() != 1234) {
      TEST_FAIL("[HttpHeaderOrigin test setToHeader case5]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderOrigin test setToHeader case100]");
}
