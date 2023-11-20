#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "HttpPacketWriter.hpp"
#include "Http2Server.hpp"
#include "NetEvent.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "Net.hpp"

using namespace obotcha;

// curl -v --http2 http://127.0.0.1:1234/aaa

// curl -v -d '12345abc' --http2 http://127.0.0.1:1234/aaa

//    curl -v -d '{"aps":{"alert":"Test Push","sound":"default"}}' \
    --cert /path/to/cert/cert.pem:SECURE_PASSWORD \
    -H "apns-topic: com.app.identifier" --http2 \
    https://api.development.push.apple.com/3/device/DEVICE_ID

CountDownLatch connectlatch = createCountDownLatch(1);
int step = 0;

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(Http2Listener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(Net)::Event::Connect: {
              
          }
          break;

          case st(Net)::Event::Message: {
                if(!msg->getEntity()->getContent()->toString()->sameAs("hello this is client")) {
                    TEST_FAIL("TestHttp2Server SimpleGetHeader test1");
                }
                
                auto header = msg->getHeader();
                auto v1 = header->get("Mytest1");
                auto v2 = header->get("Mytest2");
                
                if(!v1->sameAs("MyValue1")|| !v2->sameAs("MyValue2")) {
                    TEST_FAIL("TestHttp2Server SimpleGetHeader test2");
                }
                
                HttpResponse response = createHttpResponse();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                response->getEntity()->setContent(createString("hello this is server")->toByteArray());
                w->write(response);
                usleep(1000*10);
                connectlatch->countDown();
          }
          break;

          case st(Net)::Event::Disconnect:{
          }
          break;
      }
      
  }
};

int main() {
  int port = getEnvPort();
  MyHttpListener listener = createMyHttpListener();
  Http2Server server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(port))
                    ->setHttp2Listener(listener)
                    ->buildHttp2Server();
  server->start();
  connectlatch->await();
  server->close();
  usleep(1000*100);
  port++;
  setEnvPort(port);
  TEST_OK("TestHttp2Server SimpleGetHeader test100");

  return 0;
}
