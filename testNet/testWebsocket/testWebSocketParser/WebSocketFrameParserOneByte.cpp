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

static inline char *mask(char key[4], char *payload, size_t length) {
    size_t i, j;
    for (i = 0, j = 0; i < length; i++, j++){
        payload[i] = payload[i] ^ key[j % 4];
    }
    return payload;
}

static inline uint64_t htons64(uint64_t value) {
	static const int num = 42;

	/**
	 * If this check is true, the system is using the little endian
	 * convention. Else the system is using the big endian convention, which
	 * means that we do not have to represent our integers in another way.
	 */
	if (*(char *)&num == 42) {
        return ((uint64_t)htonl((value) & 0xFFFFFFFFLL) << 32) | htonl((value) >> 32);
	} else {
        return value;
	}
}

static void *WSS_copy(void *ptr, size_t size) {
        void *buffer;

    if (ptr == NULL) {
        return NULL;
    }

    if (NULL == (buffer = malloc(size)) ) {
        return NULL;
    }

    return memcpy(buffer, ptr, size);
}


int testWebFrameOneByteParser() {
  //case 1
#if 0
  {
      size_t offset = 0;
      const char *header = "\x81\xFE";
      const char *key = "\x37\xfa\x21\x3d";
      const char *payload = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin hendrerit ornare tortor ut euismod. Nunc finibus convallis sem, at imperdiet ligula commodo id. Nam bibendum nec augue in posuere mauris.";
      uint16_t length = strlen(payload);
      char *payload_copy = (char *)WSS_copy((void *)payload, length);
      char payload_frame[(2+2+4+length)*sizeof(char)];
      uint16_t len = htons(length);
      memcpy(payload_frame, header, 2);
      memcpy(payload_frame+2, &len, 2);
      memcpy(payload_frame+2+2, key, 4);
      memcpy(payload_frame+2+2+4, (const char *)mask((char *)key, payload_copy, length), length);

      WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
      ArrayList<WebSocketFrame> msgDatas = createArrayList<WebSocketFrame>();

      for(int i = 0;i<(2+2+4+length);i++) {
        ByteArray loadData = createByteArray(1);
        loadData[0] = payload_frame[i];
        parser->pushParseData(loadData);
        ArrayList<WebSocketFrame> datas = parser->doParse();
        msgDatas->add(datas);
      }

      if(msgDatas->size() != 1) {
        TEST_FAIL("testFrameOneByteParser case3 size is error,now is %d ",msgDatas->size());
        return -1;
      }

      WebSocketFrame frame = msgDatas->get(0);
      if(frame->getData() == nullptr) {
        TEST_FAIL("testFrameOneByteParser case3 frame check failed frame is null ");
        return -1;
      }

      if(!frame->getData()->toString()->equals(payload)) {
        TEST_FAIL("testFrameOneByteParser case3 frame check failed frame is %s ",frame->getData()->toString()->toChars());
        return -1;
      }
      free(payload_copy);
  }
#endif

  //case2
  {
    uint8_t msg[] = { 0x81u, 0x85u, 0x37u, 0xfau, 0x21u, 0x3du, 0x7fu, 0x9fu,
                  0x4du, 0x51u, 0x58u };
    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ArrayList<WebSocketFrame> msgDatas = nullptr;

    for(int i = 0; i < sizeof(msg)/sizeof(uint8_t);i++) {
      ByteArray loadData = createByteArray(1);
      loadData[0] = msg[i];
      parser->pushParseData(loadData);
      msgDatas = parser->doParse();
      if(msgDatas != nullptr && msgDatas->size()!= 0 && i != sizeof(msg)/sizeof(uint8_t) - 1) {
        TEST_FAIL("testFrameOneByteParser case4,index is %d,msgData size is %d",i,msgDatas->size());
        return -1;
      }
    }

    WebSocketFrame frame = msgDatas->get(0);
    if(frame->getHeader()->getOpCode() != 0x1) {
      TEST_FAIL("testFrameOneByteParser case5 opcode  error,opcode is %d\n",frame->getHeader()->getOpCode());
      return -1;
    }

    if(frame->getData() == nullptr || !frame->getData()->toString()->sameAs("Hello")) {
      TEST_FAIL("testFrameOneByteParser case6  error,frame is %s\n",frame->getData()->toString()->toChars());
      return -1;
    }
  }

  //case3
  {
    uint8_t msg[] = { 0x81, 0x00 };
    WebSocketHybi13Parser parser = createWebSocketHybi13Parser();
    ArrayList<WebSocketFrame> msgDatas = nullptr;

    for(int i = 0; i < sizeof(msg)/sizeof(uint8_t);i++) {
      ByteArray loadData = createByteArray(1);
      loadData[0] = msg[i];
      parser->pushParseData(loadData);
      msgDatas = parser->doParse();
      if(msgDatas != nullptr && msgDatas->size()!= 0 && i != sizeof(msg)/sizeof(uint8_t) - 1) {
        TEST_FAIL("testFrameOneByteParser case7,index is %d,msgData size is %d",i,msgDatas->size());
        return -1;
      }
    }

    if(msgDatas->size() != 1) {
      TEST_FAIL("testSimpleFrameParser case8 trace1 frame size,current is %d",msgDatas->size());
      return -1;
    }

    WebSocketFrame frame = msgDatas->get(0);
    ByteArray data = frame->getData();
    if(data != nullptr && data->size() != 0) {
      TEST_FAIL("testSimpleFrameParser case9 trace2 data size is incorrect");
      return -1;
    }
  }

  TEST_OK("testFrameOneByteParser case100");

  return 0;
}
