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
#include "NetProtocol.hpp"

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
  void onHttpMessage(int event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(NetEvent)::Connect: {
              
          }
          break;

          case st(NetEvent)::Message: {
              printf("write response connect!!! \n");
              ByteArray data = createString("hello,this is server!!!")->toByteArray();
              HttpHeader h = createHttpHeader();
              h->set("a","valuea");
              Http2Packet packet = createHttp2Packet(h,data);
              w->write(packet);
          }
          break;

          case st(NetEvent)::Disconnect:{
          }
          break;
      }
  }
};

int main() {
  MyHttpListener listener = createMyHttpListener();
  Http2Server server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(1302))
                    ->setHttp2Listener(listener)
                    ->setProtocol(st(NetProtocol)::Http_H2C)
                    ->buildHttp2Server();
  //printf("thread num is %d \n",st(Enviroment)::DefaultgHttpServerThreadsNum);
  server->start();
  connectlatch->await();
  server->close();

  printf("---TestHttpServer SimpleClientContent test100 [OK]---\n");

  return 0;
}
