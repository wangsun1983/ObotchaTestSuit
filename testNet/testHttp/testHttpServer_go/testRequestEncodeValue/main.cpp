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

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {


void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
    switch(event) {
        case st(Net)::Event::Connect: {
            //connectCount->incrementAndGet();
        }
        break;

        case st(Net)::Event::Message: {
            //messageCount->incrementAndGet();
            HttpEntity entity = msg->getEntity();
          
            HttpUrlEncodedValue v = createHttpUrlEncodedValue(entity->getContent()->toString());
            
            //printf("key1 is %s,vaue1 is %s \n",keyvalue1->getKey()->toChars(),keyvalue1->getValue()->toChars());
            if(!v->get("tag1")->sameAs("value1")) {
                TEST_FAIL("TestHttpServer Request Encode test1");
            }

            if(!v->get("tag2")->sameAs("value2")) {
                TEST_FAIL("TestHttpServer Request Encode test2");
            }
            
            HttpResponse response = createHttpResponse();
            response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
            w->write(response);
          
            latch->countDown();
        }
        break;

        case st(Net)::Event::Disconnect:{
            //disConnectCount->incrementAndGet();
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
   
  port++;
  setEnvPort(port);
  
  TEST_OK("TestHttpServer Request Encode test100");
}
