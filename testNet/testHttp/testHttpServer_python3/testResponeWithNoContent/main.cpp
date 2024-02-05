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
#include "AtomicNumber.hpp"

using namespace obotcha;

AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disConnectCount = createAtomicInteger(0);
AtomicInteger messageCount = createAtomicInteger(0);

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {


void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
    switch(event) {
        case st(Net)::Event::Connect: {
            //connectCount->incrementAndGet();
        }
        break;

        case st(Net)::Event::Message: {
            messageCount->incrementAndGet();
            HttpResponse response = createHttpResponse();
            response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
            w->write(response);
        }
        break;

        case st(Net)::Event::Disconnect:{
            //disConnectCount->incrementAndGet();
            latch->countDown();
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
  
  TEST_OK("TestHttpServer No Content test100");
}
