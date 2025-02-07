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

CountDownLatch connectlatch = CountDownLatch::New(1);
int step = 0;

ByteArray sendData = ByteArray::New(1024*1024*2);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(Http2Listener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(Net)::Event::Connect: {
          }
          break;

          case st(Net)::Event::Message: {
                printf("write responce from server11111 \n");
                HttpResponse response = HttpResponse::New();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                response->getEntity()->setContent(String::New("hello this is server")->toByteArray());
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
  int port = getEnvPort();
  MyHttpListener listener = MyHttpListener::New();
  Http2Server server = HttpServerBuilder::New()
                    ->setAddress(Inet4Address::New(8080))
                    ->setHttp2Listener(listener)
                    ->buildHttp2Server();
  server->start();
  connectlatch->await();
  server->close();
  usleep(1000*100);
  port++;
  setEnvPort(port);
  TEST_OK("TestHttp2Server SimpleConnect test100");

  return 0;
}
