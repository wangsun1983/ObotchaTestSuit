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


#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disConnectCount = createAtomicInteger(0);
AtomicInteger messageCount = createAtomicInteger(0);

CountDownLatch messageLatch = createCountDownLatch(1024*128);


DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("messageLatch is %d \n",messageLatch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(int event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(NetEvent)::Connect: {
              //connectlatch->countDown();
          }
          break;

          case st(NetEvent)::Message: {
              auto data = msg->getEntity()->getContent()->toString();
              printf("get data is %s \n",data->toChars());
              if(data->equals("hello world")) {
                messageLatch->countDown();
              }
              
              HttpResponse response = createHttpResponse();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              HttpEntity entity = createHttpEntity();
              ByteArray rdata = createString("sss")->toByteArray();
              entity->setContent(rdata);
              response->setEntity(entity);

              w->write(response);
          }
          break;

          case st(NetEvent)::Disconnect:{
              //disconnetlatch->countDown();
          }
          break;
      }
  }
};

int main() {
  int port = getEnvPort();
  MyHttpListener listener = createMyHttpListener();
  HttpServer server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(port))
                    ->setListener(listener)
                    ->build();
  server->start();
  MyHandler h = createMyHandler();
  h->sendEmptyMessageDelayed(0,10*1024);
  messageLatch->await();
  server->close();
  
  port++;
  setEnvPort(port);
  TEST_OK("TestHttpServer MultiClientMessage test100");
}
