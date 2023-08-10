#include "HttpPacketParserImpl.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testMultiMessageParse() {

  //case1
  while(1) {
    const char *content = "GET /test HTTP/1.1\r\n"
                 "User-Agent: curl/7.18.0 (i486-pc-linux-gnu) libcurl/7.18.0 OpenSSL/0.9.8g zlib/1.2.3.3 libidn/1.1\r\n"
                 "Host: 0.0.0.0=5000\r\n"
                 "Accept: */*\r\n"
                 "\r\n"
                 "GET /test HTTP/1.1\r\n"
                "User-Agent: curl/7.18.0 (i486-pc-linux-gnu) libcurl/7.18.0 OpenSSL/0.9.8g zlib/1.2.3.3 libidn/1.1\r\n"
                "Host: 0.0.0.0=5000\r\n"
                "Accept: */*\r\n"
                "\r\n";

    HttpPacketParserImpl parser = createHttpPacketParserImpl();

    parser->pushData(createByteArray(( byte *)content,strlen(content)));
    ArrayList<HttpPacket> packets = parser->doParse();
    if(packets->size() != 2) {
      TEST_FAIL("HttpPacketParser multi message parse case1");
    }
    break;
  }

  //case2
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

    parser->pushData(createByteArray((byte *)content,strlen(content)));
    ArrayList<HttpPacket> packets = parser->doParse();
    if(packets->size() != 2) {
      TEST_FAIL("HttpPacketParser multi message parse case2");
      break;
    }

    auto pac0 = packets->get(0);
    if(!pac0->getEntity()->getContent()->toString()->sameAs("HELLO")) {
      TEST_FAIL("HttpPacketParser multi message parse case3");
      break;
    }

    auto pac1 = packets->get(1);
    if(!pac1->getEntity()->getContent()->toString()->sameAs("WORLD")) {
      TEST_FAIL("HttpPacketParser multi message parse case4");
      break;
    }

    break;
  }

  //case3
  while(1) {
    const char *content = "GET /get_funky_content_length_body_hello HTTP/1.0\r\n"
                 "conTENT-Length: 5\r\n"
                 "\r\n"
                 "HELLO"
                 "GET /get_funky_content_length_body_hello HTTP/1.0\r\n"
                              "conTENT-Length: 5\r\n";


    HttpPacketParserImpl parser = createHttpPacketParserImpl();

    parser->pushData(createByteArray((byte *)content,strlen(content)));
    ArrayList<HttpPacket> packets = parser->doParse();
    if(packets->size() != 1) {
      TEST_FAIL("HttpPacketParser multi message parse case3");
      break;
    }

    auto pac0 = packets->get(0);
    if(!pac0->getEntity()->getContent()->toString()->sameAs("HELLO")) {
      TEST_FAIL("HttpPacketParser multi message parse case4");
      break;
    }

    const char* content2 = "\r\n"
                            "WORLD";
    parser->pushData(createByteArray((byte *)content2,strlen(content2)));
    packets = parser->doParse();
    if(packets->size() != 1) {
      TEST_FAIL("HttpPacketParser multi message parse case5");
      break;
    }

    auto pac1 = packets->get(0);
    if(!pac1->getEntity()->getContent()->toString()->sameAs("WORLD")) {
      TEST_FAIL("HttpPacketParser multi message parse case6");
      break;
    }

    break;
  }

  //case4
  while(1) {
    const char *content = "GET /get_funky_content_length_body_hello HTTP/1.0\r\n"
                 "conTENT-Length: 5\r\n"
                 "\r\n"
                 "HELLO";
    HttpPacketParserImpl parser = createHttpPacketParserImpl();
    ArrayList<HttpPacket> packets;
    int i = 0;

    for(;i<strlen(content);i++) {
      ByteArray data = createByteArray(1);
      data[0] = (byte)content[i];
      parser->pushData(data);
      packets = parser->doParse();
    }

    if(i != strlen(content)) {
      TEST_FAIL("HttpPacketParser multi message parse case7,i is %d,strlen(content) is %d",i,strlen(content));
      break;
    }

    auto pac1 = packets->get(0);
    if(!pac1->getEntity()->getContent()->toString()->sameAs("HELLO")) {
      TEST_FAIL("HttpPacketParser multi message parse case8");
      break;
    }
    break;
  }

  //case5
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
    ArrayList<HttpPacket> packets = createArrayList<HttpPacket>();
    int i = 0;

    for(;i<strlen(content);i++) {
      ByteArray data = createByteArray(1);
      data[0] = (byte)content[i];
      parser->pushData(data);
      auto ret = parser->doParse();
      packets->add(ret);
    }

    if(i != strlen(content)) {
      TEST_FAIL("HttpPacketParser multi message parse case9,i is %d,strlen(content) is %d",i,strlen(content));
      break;
    }

    auto pac1 = packets->get(0);
    if(!pac1->getEntity()->getContent()->toString()->sameAs("HELLO")) {
      TEST_FAIL("HttpPacketParser multi message parse case10");
      break;
    }

    auto pac2 = packets->get(1);
    if(!pac2->getEntity()->getContent()->toString()->sameAs("WORLD")) {
      TEST_FAIL("HttpPacketParser multi message parse case11");
      break;
    }
    break;
  }

  TEST_OK("HttpPacketParser multi message parse case100");
}
