#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderSecWebSocketVersion.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Sec-WebSocket-Version"),String::New("13"));
    auto c = header->getWebSocketVersion();
    if(c->get() != 13) {
      TEST_FAIL("[HttpHeaderSecWebSocketVersion test setToHeader case1]");
      break;
    }
    
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketVersion test setToHeader case100]");

}
