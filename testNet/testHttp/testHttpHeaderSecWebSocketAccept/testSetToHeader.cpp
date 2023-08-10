#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketAccept.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = createHttpHeaderSecWebSocketKey();
    HttpHeader header = createHttpHeader();
    header->set(createString("Sec-WebSocket-Accept"),createString(" s3pPLMBiTxaQ9kYGzzhZRbK+xOo="));
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketAccept();
    if(!key->get()->sameAs("s3pPLMBiTxaQ9kYGzzhZRbK+xOo=")) {
      TEST_FAIL("[HttpHeaderSecWebSocketAccept test setToHeader case1]");
    }
    break;
  }
  
  TEST_OK("[HttpHeaderSecWebSocketKey test setToHeader case100]");
}
