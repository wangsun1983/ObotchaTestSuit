#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpPacketWriter.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "AtomicNumber.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

AtomicInteger connectCount = AtomicInteger::New(0);
AtomicInteger disConnectCount = AtomicInteger::New(0);
AtomicInteger messageCount = AtomicInteger::New(0);

CountDownLatch messageLatch = CountDownLatch::New(1024*32);


DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("messageLatch is %d \n",messageLatch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              //connectlatch->countDown();
          }
          break;

          case st(Net)::Event::Message: {
              auto data = msg->getEntity()->getContent()->toString();
              //printf("get data is %s \n",data->toChars());
              if(data->sameAs("hello world")) {
                messageLatch->countDown();
              }
              
              HttpResponse response = HttpResponse::New();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              HttpEntity entity = HttpEntity::New();
              ByteArray rdata = String::New("sss")->toByteArray();
              entity->setContent(rdata);
              response->setEntity(entity);

              w->write(response);
          }
          break;

          case st(Net)::Event::Disconnect:{
              //disconnetlatch->countDown();
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
  MyHandler h = MyHandler::New();
  h->sendEmptyMessageDelayed(0,10*1024);
  messageLatch->await();
  server->close();
  
  port++;
  setEnvPort(port);
  TEST_OK("TestHttpServer MultiClientMessage test100");
}
