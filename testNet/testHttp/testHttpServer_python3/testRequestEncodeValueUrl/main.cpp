#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpPacketParser.hpp"
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

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {


void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
    switch(event) {
        case st(Net)::Event::Connect: {
            //connectCount->incrementAndGet();
        }
        break;

        case st(Net)::Event::Message: {
            //messageCount->incrementAndGet();
            HttpHeader header = msg->getHeader();
            HttpUrl url = header->getUrl();
            auto queryParams = url->getQuery();
            auto v1 = queryParams->get("tag1");
            if(!v1->sameAs("value1")) {
                TEST_FAIL("TestHttpServer Request Url Encode test1");
            }

            auto v2 = queryParams->get("tag2");
            if(!v2->sameAs("value2")) {
                TEST_FAIL("TestHttpServer Request Url Encode test2");
            }

            HttpResponse response = HttpResponse::New();
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
  latch->await();

  port++;
  setEnvPort(port);
  TEST_OK("TestHttpServer Request Encode test100");
}
