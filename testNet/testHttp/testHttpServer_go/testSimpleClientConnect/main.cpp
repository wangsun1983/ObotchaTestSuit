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

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;


CountDownLatch connectlatch = CountDownLatch::New(1);
int step = 0;

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("connectlatch is %d \n",connectlatch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {

          }
          break;

          case st(Net)::Event::Message: {
              if(step == 0) {
                HttpResponse response = HttpResponse::New();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                response->getEntity()->setContent(String::New("hello this is server")->toByteArray());
                w->write(response);
                step = 1;
              } else {
                String entity = msg->getEntity()->getContent()->toString();
                if(!entity->sameAs("hello this is client")) {
                  TEST_FAIL("TestHttpServer_Go SimpleClientContent test1,entity is %s",entity->toChars());
                }
                connectlatch->countDown();
              }
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
  HttpServer server = nullptr;
  while(1) {
    server = HttpServerBuilder::New()
                    ->setAddress(Inet4Address::New(port))
                    ->setListener(listener)
                    ->build();
    if(server->start() == -1) {
        port++;
        continue;
    }
    setEnvPort(port);
    break;
  }
  //printf("thread num is %d \n",st(Enviroment)::DefaultgHttpServerThreadsNum);
  server->start();
  MyHandler h = MyHandler::New();
  h->sendEmptyMessageDelayed(0,10*1024);

  connectlatch->await();
  server->close();

  port++;
  setEnvPort(port);

  TEST_OK("TestHttpServer_Go SimpleClientContent test100");

  return 0;
}
