#include "HttpPacketParser.hpp"
#include "HttpPacketParserImpl.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testChunkTailingOneByteParse() {

  //case 1
  while(1) {
    const char *content = "POST /chunked_w_trailing_headers HTTP/1.1\r\n"
                 "Transfer-Encoding: chunked\r\n"
                 "\r\n"
                 "5\r\nhello\r\n"
                 "6\r\n world\r\n"
                 "0\r\n"
                 "Vary: *\r\n"
                 "Content-Type: text/plain\r\n"
                 "\r\n";

    HttpPacketParserImpl parser = createHttpPacketParserImpl();
    ArrayList<HttpPacket> packets = createArrayList<HttpPacket>();
    int i = 0;
    for(;i<strlen(content);i++) {
      ByteArray data = createByteArray(1);
      data[0] = (byte)content[i];

      parser->pushData(data);
      auto packet = parser->doParse();
      if(packet != nullptr) {
        packets->add(packet);
      }
    }

    if(packets->size() != 1) {
      TEST_FAIL("HttpPacketParser chunk tailing message one byte parse case11 ,packets is %d",packets->size());
      break;
    }

    break;
  }


  TEST_OK("HttpPacketParser chunk tailing message one byte parse case100");
}
