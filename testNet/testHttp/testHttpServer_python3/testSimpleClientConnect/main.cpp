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
#include "HttpMethod.hpp"
#include "NetEvent.hpp"
#include "AtomicNumber.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

bool testResult = false;

AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disConnectCount = createAtomicInteger(0);
AtomicInteger messageCount = createAtomicInteger(0);

CountDownLatch connectlatch = createCountDownLatch(1);
CountDownLatch disconnetlatch = createCountDownLatch(1);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("connect is %d,disconnect is %d \n",connectlatch->getCount(),disconnetlatch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
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
              if(msg->getHeader()->getMethod() == st(HttpMethod)::Id::Get) {
                HttpResponse response = createHttpResponse();
                HttpEntity entity = createHttpEntity();
                entity->setContent(createString("this is server")->toByteArray());
                response->setEntity(entity);
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
              } else if(msg->getHeader()->getMethod() == st(HttpMethod)::Id::Post) {
                String str = msg->getEntity()->getContent()->toString();
                if(!str->sameAs("i am client")) {
                  TEST_FAIL("TestHttpServer SimpleClientConnect test1");
                } else {
                  testResult = true;
                }
              }
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
  //printf("thread num is %d \n",st(Enviroment)::DefaultgHttpServerThreadsNum);
  server->start();
  MyHandler h = createMyHandler();
  h->sendEmptyMessageDelayed(0,10*1024);
  connectlatch->await();
  disconnetlatch->await();
  server->close();
  
  if(testResult) {
    TEST_OK("TestHttpServer SimpleClientConnect test100");
  } else {
    TEST_FAIL("TestHttpServer SimpleClientConnect test2");
  }

  port++;
  setEnvPort(port);
  
}
