#include <stdio.h>
#include <unistd.h>

#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "WebSocketServer.hpp"
#include "WebSocketListener.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "WebSocketProtocol.hpp"
#include "WebSocketComposer.hpp"
#include "File.hpp"
#include "FileOutputStream.hpp"
#include "WebSocketHybi13Parser.hpp"
#include "TestLog.hpp"

using namespace obotcha;


int testFrameParserException() {
  //case 1
  {
    //0x88 0x80 0xb3 0x24 0xb2 0x4e
    size_t offset = 0;
    const char *payload = "\x81\x85\x37\xfa\x21\x3d\x7f\x9f\x4d\x51\x58";
    uint16_t length = strlen(payload);
    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ByteArray loadData = createByteArray((const byte *)payload,strlen(payload));
    parser->pushParseData(loadData);
    ArrayList<WebSocketFrame> msgDatas = parser->doParse();
    if(msgDatas->size() == 0) {
      TEST_FAIL("testFrameParserException case1 size check ,it is 0 ");
      return -1;
    }

    WebSocketFrame frame = msgDatas->get(0);
    if(frame->getData() == nullptr) {
      TEST_FAIL("testFrameParserException case1 frame check frame is null ");
      return -1;
    }

    if(!frame->getData()->toString()->sameAs("Hello")) {
      TEST_FAIL("testFrameParserException case1 frame check frame is %s ",frame->getData()->toString()->toChars());
    }
  }

  TEST_OK("testFrameParserException");
  return 0;
}
