#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderKeepAlive.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Keep-Alive"),
                createString("timeout=5, max=1000"));
                
    HttpHeaderKeepAlive keepAlive = header->getKeepAlive();
    if(keepAlive->getTimeout() != 5 || keepAlive->getMax() != 1000) {
      TEST_FAIL("[HttpHeaderKeepAlive test SetToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Keep-Alive"),
                createString("1000"));
                
    HttpHeaderKeepAlive keepAlive = header->getKeepAlive();
    if(keepAlive->getTimeout() != 1000) {
      TEST_FAIL("[HttpHeaderKeepAlive test SetToHeader case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Keep-Alive"),
                createString("timeout=5"));
    
    auto keepAlive = header->getKeepAlive();
    keepAlive->load("timeout=5");
    if(keepAlive->getTimeout() != 5) {
      TEST_FAIL("[HttpHeaderKeepAlive test SetToHeader case3]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Keep-Alive"),
                createString("Max=5"));
    
    auto keepAlive = header->getKeepAlive();
    if(keepAlive->getMax() != 5) {
      TEST_FAIL("[HttpHeaderKeepAlive test SetToHeader case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderKeepAlive test SetToHeader case100]");
}
