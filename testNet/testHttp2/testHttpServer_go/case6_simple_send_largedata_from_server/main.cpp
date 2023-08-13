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
#include "Enviroment.hpp"
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
long size = 0;

ByteArray sendData = createByteArray(1024*64);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(Http2Listener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(Net)::Event::Connect: {
              
          }
          break;

          case st(Net)::Event::Message: {
            HttpResponse response = createHttpResponse();
            response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
            response->getEntity()->setContent(sendData);
            w->write(response);
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
  for(long i = 0; i < 1024*64;i++) {
      sendData[i] = i % 32;
  }
  
  int port = getEnvPort();
  MyHttpListener listener = createMyHttpListener();
  Http2Server server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(8080))
                    ->setHttp2Listener(listener)
                    ->buildHttp2Server();
  server->start();
  connectlatch->await();
  usleep(1000*1000*20);
  server->close();
  port++;
  setEnvPort(port);
  TEST_OK("TestHttp2Server Simple Large data test100");

  return 0;
}
