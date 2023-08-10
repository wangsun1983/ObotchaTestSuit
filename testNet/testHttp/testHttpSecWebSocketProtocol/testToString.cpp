#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketProtocol.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketProtocol c = createHttpHeaderSecWebSocketProtocol();
    c->load("  chat, superchat");
    if(!c->toString()->sameAs("chat, superchat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test toString case1],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderSecWebSocketProtocol c = createHttpHeaderSecWebSocketProtocol();
    c->load("  chat, superchat");
    
    header->setWebSocketProtocol(c);
    auto c2 = header->getWebSocketProtocol();
    if(!c2->toString()->sameAs("chat, superchat")) {
      TEST_FAIL("[HttpHeaderSecWebSocketProtocol test toString case2],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketProtocol test toString case100]");

}
