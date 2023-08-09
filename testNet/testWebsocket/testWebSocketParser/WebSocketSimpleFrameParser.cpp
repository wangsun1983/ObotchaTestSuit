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
#include "WebSocketProtocol.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct scripted_data_feed {
  uint8_t data[8192];
  uint8_t* datamark;
  uint8_t* datalimit;
  size_t feedseq[8192];
  size_t seqidx;
};

static void scripted_data_feed_init(struct scripted_data_feed *df,
                                    uint8_t *data, size_t data_length)
{
  memset(df, 0, sizeof(struct scripted_data_feed));
  memcpy(df->data, data, data_length);
  df->datamark = df->data;
  df->datalimit = df->data+data_length;
  df->feedseq[0] = data_length;
}

int testSimpleFrameParser() {

  //case 1
  {
      uint8_t msg[] = { 0x81u, 0x85u, 0x37u, 0xfau, 0x21u, 0x3du, 0x7fu, 0x9fu,
                    0x4du, 0x51u, 0x58u };
      WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
      ByteArray loadData = createByteArray((const byte *)msg,sizeof(msg)/sizeof(uint8_t));
      parser->pushParseData(loadData);
      ArrayList<WebSocketFrame> msgDatas = parser->doParse();
      WebSocketFrame frame = msgDatas->get(0);
      if(frame->getHeader()->getOpCode() != 0x1) {
        TEST_FAIL("testSimpleFrameParser case1 opcode  error,opcode is %d\n",frame->getHeader()->getOpCode());
        return -1;
      }

      if(frame->getData() == nullptr || !frame->getData()->toString()->sameAs("Hello")) {
        TEST_FAIL("testSimpleFrameParser case2  error,frame is %s\n",frame->getData()->toString()->toChars());
        return -1;
      }
  }

  //case 2
  {
    uint8_t msg[] = { 0x01, 0x03, 0x48, 0x65, 0x6c, /* "Hel" */
                    0x80, 0x02, 0x6c, 0x6f }; /* "lo" */
    printf("start test case 2 \n");
    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ByteArray loadData = createByteArray((const byte *)msg,sizeof(msg)/sizeof(uint8_t));
    parser->pushParseData(loadData);
    ArrayList<WebSocketFrame> msgDatas = parser->doParse();

    WebSocketFrame frame = msgDatas->get(0);
    if(frame->getHeader()->getOpCode() != 0x1) {
      TEST_FAIL("testSimpleFrameParser case2 opcode  error,opcode is %d\n",frame->getHeader()->getOpCode());
      return -1;
    }

    if(frame->getData() == nullptr || !frame->getData()->toString()->sameAs("Hel")) {
      TEST_FAIL("testSimpleFrameParser case2  error,frame is %s\n",frame->getData()->toString()->toChars());
      return -1;
    }

    frame = msgDatas->get(1);
    
    if(frame->getHeader()->getOpCode() != 0x0) {
      TEST_FAIL("testSimpleFrameParser case2 trace1 opcode  error,opcode is %d\n",frame->getHeader()->getOpCode());
      return -1;
    }

    if(frame->getData() == nullptr ) {
      TEST_FAIL("testSimpleFrameParser case2  trace1 error,tframe is nullptr\n");
      return -1;
    }
  }

  //case 3
  {
    uint8_t msg[] = { 0x01, 0x03, 0x48, 0x65, 0x6c, /* "Hel" */
                  /* ping with "Hello" */
                  0x89, 0x05, 0x48, 0x65, 0x6c, 0x6c, 0x6f,
                  0x80, 0x02, 0x6c, 0x6f }; /* "lo" */

    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ByteArray loadData = createByteArray((const byte *)msg,sizeof(msg)/sizeof(uint8_t));
    parser->pushParseData(loadData);
    ArrayList<WebSocketFrame> msgDatas = parser->doParse();

    if(msgDatas->size() != 3) {
      TEST_FAIL("testSimpleFrameParser case3 trace1 size is error,current is %d",msgDatas->size());
      return -1;
    }

    WebSocketFrame frame = msgDatas->get(0);
    if(frame->getHeader()->isFinalFrame()) {
      TEST_FAIL("testSimpleFrameParser case3 trace2 not final frame");
      return -1;
    }

    ByteArray data = frame->getData();
    if(data == nullptr || !data->toString()->sameAs("Hel")) {
      TEST_FAIL("testSimpleFrameParser case3 trace3 frame content is not equal");
      return -1;
    }

    if(frame->getHeader()->getOpCode() != st(WebSocketProtocol)::OPCODE_TEXT) {
      TEST_FAIL("testSimpleFrameParser case3 trace4 opcode is error,current is %d",frame->getHeader()->getOpCode());
      return -1;
    }

    frame = msgDatas->get(1);
    if(!frame->getHeader()->isFinalFrame()) {
      TEST_FAIL("testSimpleFrameParser case3 trace5 not final frame");
      return -1;
    }

    data = frame->getData();
    if(data == nullptr || !data->toString()->sameAs("Hello")) {
      TEST_FAIL("testSimpleFrameParser case3 trace6 frame content is not equal");
      return -1;
    }

    if(frame->getHeader()->getOpCode() != st(WebSocketProtocol)::OPCODE_CONTROL_PING) {
      TEST_FAIL("testSimpleFrameParser case3 trace7 opcode is error,current is %d",frame->getHeader()->getOpCode());
      return -1;
    }

    frame = msgDatas->get(2);
    if(!frame->getHeader()->isFinalFrame()) {
      TEST_FAIL("testSimpleFrameParser case3 trace8 not final frame");
      return -1;
    }

    data = frame->getData();
    if(data == nullptr || !data->toString()->sameAs("lo")) {
      TEST_FAIL("testSimpleFrameParser case3 trace9 frame content is not equal");
      return -1;
    }

    if(frame->getHeader()->getOpCode() != st(WebSocketProtocol)::OPCODE_CONTINUATION) {
      TEST_FAIL("testSimpleFrameParser case3 trace10 opcode is error,current is %d",frame->getHeader()->getOpCode());
      return -1;
    }
  }


  //case4
  {
    uint8_t msg[] = { 0x81, 0x00 };

    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ByteArray loadData = createByteArray((const byte *)msg,sizeof(msg)/sizeof(uint8_t));
    parser->pushParseData(loadData);
    ArrayList<WebSocketFrame> msgDatas = parser->doParse();

    if(msgDatas->size() != 1) {
      TEST_FAIL("testSimpleFrameParser case4 trace1 frame size,current is %d",msgDatas->size());
      return -1;
    }

    WebSocketFrame frame = msgDatas->get(0);
    ByteArray data = frame->getData();
    if(data != nullptr && data->size() != 0) {
      TEST_FAIL("testSimpleFrameParser case4 trace2 data size is incorrect");
      return -1;
    }
  }

  //case5
  {
    uint8_t msg[] = { 0x81, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ByteArray loadData = createByteArray((const byte *)msg,sizeof(msg)/sizeof(uint8_t));

    parser->pushParseData(loadData);
    try {
        ArrayList<WebSocketFrame> msgDatas = parser->doParse();
        TEST_FAIL("testSimpleFrameParser case5 trace1 frame size,current is %d",msgDatas->size());
    } catch(...) {
    
    }
  }

  TEST_OK("testSimpleFrameParser case100");
  return 0;

}
