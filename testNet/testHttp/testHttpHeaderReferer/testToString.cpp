#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferer.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderReferer match = HttpHeaderReferer::New();
    match->load("");

    if(!match->toString()->sameAs("")){
      TEST_FAIL("[HttpHeaderReferer test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderReferer match = HttpHeaderReferer::New();
    match->load("https://developer.mozilla.org:1234");
    if(!match->toString()->sameAs("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderReferer test toString case2]");
      break;
    }

    break;
  }
  
  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderReferer match_0 = HttpHeaderReferer::New();
    match_0->load("https://developer.mozilla.org:1234");
    header->setReferer(match_0);
    
    auto match = header->getReferer();
    if(!match->toString()->sameAs("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderReferer test toString case3]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderReferer test toString case100]");
}
