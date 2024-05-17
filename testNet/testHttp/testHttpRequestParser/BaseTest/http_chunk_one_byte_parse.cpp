#include "HttpPacketParser.hpp"
#include "HttpPacketParserImpl.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testChunkOneByteParse() {

  //case 1
  while(1) {
    const char *content = "POST /two_chunks_mult_zero_end HTTP/1.1\r\n"
                 "Transfer-Encoding: chunked\r\n"
                 "\r\n"
                 "5\r\nhello\r\n"
                 "6\r\n world\r\n"
                 "000\r\n"
                 "\r\n";

    HttpPacketParserImpl parser = HttpPacketParserImpl::New();
    ArrayList<HttpPacket> packets = ArrayList<HttpPacket>::New();
    int i = 0;
    for(;i<strlen(content);i++) {
      ByteArray data = ByteArray::New(1);
      data[0] = (byte)content[i];

      parser->pushData(data);
      auto packet = parser->doParse();
      if(packet != nullptr) {
        packets->add(packet);
      }
    }

    if(packets->size() != 1) {
      TEST_FAIL("HttpPacketParser chunk message one byte parse case11 ,packets is %d \n",packets->size());
      break;
    }

    break;
  }


  TEST_OK("HttpPacketParser chunk message one byte parse case100");
}
