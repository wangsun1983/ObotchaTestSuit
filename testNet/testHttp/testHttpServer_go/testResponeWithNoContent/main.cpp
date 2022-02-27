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

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disConnectCount = createAtomicInteger(0);
AtomicInteger messageCount = createAtomicInteger(0);

CountDownLatch latch = createCountDownLatch(1);
int step = 0;

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {

void onHttpMessage(int event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
    switch(event) {
        case st(NetEvent)::Connect: {
            //connectCount->incrementAndGet();
        }
        break;

        case st(NetEvent)::Message: {
            if(step == 0) {
              messageCount->incrementAndGet();
              HttpResponse response = createHttpResponse();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              w->write(response);
              step++;
            } else {
              String entity = msg->getEntity()->getContent()->toString();
              if(!entity->equals("hello this is client")) {
                TEST_FAIL("TestHttpServer_Go SimpleClientContent test1,entity is %s",entity->toChars());
              }
              latch->countDown();
            }
        }
        break;

        case st(NetEvent)::Disconnect:{
            //disConnectCount->incrementAndGet();
            //latch->countDown();
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
  latch->await();
  server->close();

  port++;
  setEnvPort(port);

  TEST_OK("TestHttpServer_Go No Content test100");
}
