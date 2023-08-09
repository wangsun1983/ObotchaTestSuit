#include "HttpPacketParserImpl.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testRepeatRequest() {

  while(1) {
    const char *content = "GET /get_funky_content_length_body_hello HTTP/1.0\r\n"
                 "conTENT-Length: 5\r\n"
                 "\r\n"
                 "HELLO"
                 "GET /get_funky_content_length_body_hello HTTP/1.0\r\n"
                              "conTENT-Length: 5\r\n"
                              "\r\n"
                              "WORLD";
    HttpPacketParserImpl parser = createHttpPacketParserImpl();
    int index = 0;
    while(index < 1024*32) {
      parser->pushData(createByteArray((byte *)content,strlen(content)));
      ArrayList<HttpPacket> packets = parser->doParse();
      if(packets->size() != 2) {
        TEST_FAIL("HttpPacketParser repeat message parse case2");
        break;
      }

      auto pac0 = packets->get(0);
      if(!pac0->getEntity()->getContent()->toString()->sameAs("HELLO")) {
        TEST_FAIL("HttpPacketParser repeat message parse case3");
        break;
      }

      auto pac1 = packets->get(1);
      if(!pac1->getEntity()->getContent()->toString()->sameAs("WORLD")) {
        TEST_FAIL("HttpPacketParser repeat message parse case4");
        break;
      }
      index++;
    }

    break;
  }

  TEST_OK("HttpPacketParser repeat message parse case4");
}
