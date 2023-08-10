#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderKeepAlive.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->load("timeout=5, max=1000");
    if(!keepAlive->toString()->sameAs("timeout=5, max=1000")) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->load("1000");
    if(!keepAlive->toString()->sameAs("timeout=1000")) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->load("timeout=5");
    if(!keepAlive->toString()->sameAs("timeout=5")) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case3]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->load("Max=5");
    if(!keepAlive->toString()->sameAs("max=5")) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case4]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderKeepAlive keepAlive = createHttpHeaderKeepAlive();
    keepAlive->setTimeout(5);
    keepAlive->setMax(1000);
    if(!keepAlive->toString()->sameAs("timeout=5, max=1000")) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case5]");
      break;
    }
    
    if(keepAlive->getTimeout() != 5 || keepAlive->getMax() != 1000) {
      TEST_FAIL("[HttpHeaderKeepAlive test toString case6]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderKeepAlive test toString case100]");
}
