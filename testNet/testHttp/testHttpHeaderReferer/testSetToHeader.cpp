#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "Net.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Referer"),
                createString(""));
    auto match = header->getReferer();
    
    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderReferer test SetToHeader case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Referer"),
                createString("https://developer.mozilla.org:1234"));
    auto match = header->getReferer();

    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderReferer test SetToHeader case2]");
      break;
    }

    if(url->getScheme() != st(Net)::Protocol::Https) {
      TEST_FAIL("[HttpHeaderReferer test SetToHeader case3]");
      break;
    }

    if(!url->getHost()->sameAs("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderReferer test SetToHeader case4]");
      break;
    }

    if(url->getPort() != 1234) {
      TEST_FAIL("[HttpHeaderReferer test SetToHeader case5]");
      break;
    }

    break;
  }
  TEST_OK("[HttpHeaderReferer test SetToHeader case100]");
}
