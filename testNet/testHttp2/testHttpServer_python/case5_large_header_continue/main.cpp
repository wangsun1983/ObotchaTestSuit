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

int count = 0;
String respStr;
CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(Http2Listener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(Net)::Event::Connect: {
              
          }
          break;

          case st(Net)::Event::Message: {
            HttpResponse response = createHttpResponse();
            response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
            for(int i = 0;i < 1024 * 4;i++) {
                String header = createString(i);
                String value = header->append("a");
                response->getHeader()->set(header,value);
            }
            response->getHeader()->set(createString("mydata"),createString("myvalue"));
            //response->getEntity()->setContent(createString("hello this is server")->toByteArray());
            w->write(response);
            
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
                    ->setAddress(createInet4Address(8080))
                    ->setHttp2Listener(listener)
                    ->buildHttp2Server();
  server->start();
  // latch->await();
  // server->close();
  // usleep(1000*100);
  // if(respStr == nullptr || !respStr->sameAs("hello this is server")) {
  //     TEST_FAIL("TestHttp2Server SimpleConnect case1");
  // }
  latch->await();
  port++;
  setEnvPort(port);
  TEST_OK("TestHttp2Server SimpleConnect case100");

  return 0;
}
