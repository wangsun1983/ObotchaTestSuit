#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderOrigin.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderOrigin match = createHttpHeaderOrigin();
    match->load("");
    
    if(!match->toString()->sameAs("")){
      TEST_FAIL("[HttpHeaderOrigin test toString case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderOrigin match = createHttpHeaderOrigin();
    match->load("https://developer.mozilla.org:1234");
    if(!match->toString()->sameAs("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderOrigin test toString case2]");
      break;
    }

    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderOrigin match = createHttpHeaderOrigin();
    match->load("https://developer.mozilla.org:1234");
    header->setOrigin(match);
    auto match2 = header->getOrigin();
    if(!match2->toString()->sameAs("https://developer.mozilla.org:1234")){
      TEST_FAIL("[HttpHeaderOrigin test toString case3]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderOrigin test toString case100]");
}
