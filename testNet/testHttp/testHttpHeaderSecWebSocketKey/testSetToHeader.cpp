#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketKey.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    HttpHeader header = createHttpHeader();
    header->set(createString("sec-websocket-key"),createString(" abc"));
    //upgrade->import(" websocket ");
    auto key = header->getWebSocketKey();
    if(!key->get()->equals("abc")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case1]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    HttpHeader header = createHttpHeader();
    HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    upgrade->import(" websocket ");
    header->setWebSocketKey(upgrade);
    
    //upgrade->import(" websocket ");
    auto key = header->getWebSocketKey();
    if(!key->get()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketKey test setToHeader case100]");
}
