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
#include "AtomicNumber.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disConnectCount = createAtomicInteger(0);
AtomicInteger messageCount = createAtomicInteger(0);

CountDownLatch connectlatch = createCountDownLatch(1024*32);
CountDownLatch disconnetlatch = createCountDownLatch(1024*32);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("connect is %d,disconnect is %d,message is %d \n",
            connectlatch->getCount(),disconnetlatch->getCount(),messageCount->get());
    this->sendEmptyMessageDelayed(0,1*1000);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              connectlatch->countDown();
          }
          break;

          case st(Net)::Event::Message: {
              HttpResponse response = createHttpResponse();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              response->getEntity()->setContent(createString(messageCount->getAndIncrement())->toByteArray());
              if(w->write(response) < 0) {
                  printf("failed to write,err is %s \n",strerror(errno));
              }
              //messageCount->incrementAndGet();
          }
          break;

          case st(Net)::Event::Disconnect:{
              disconnetlatch->countDown();
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
  h->sendEmptyMessageDelayed(0,1*1000);
  connectlatch->await();
  disconnetlatch->await();
  server->close();
  
  usleep(1000*100);
  if(messageCount->get() != 1024*32) {
    TEST_FAIL("TestHttpServer MultiClientConnect case1,count is %d",messageCount->get());
  }
  port++;
  setEnvPort(port);
  TEST_OK("TestHttpServer MultiClientConnect case2");
}
