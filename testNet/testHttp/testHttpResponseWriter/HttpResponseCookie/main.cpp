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
#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);
int count = 0;


DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              //connectlatch->countDown();
          }
          break;

          case st(Net)::Event::Message: {
              if(count == 0) {
                //first message to send response with cookie
                HttpResponse response = HttpResponse::New();
                HttpCookie cookie1 = HttpCookie::New("test_tag1","test_value1");
                HttpCookie cookie2 = HttpCookie::New("test_tag2","test_value2");
                response->getHeader()->addCookie(cookie1);
                response->getHeader()->addCookie(cookie2);
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
                count++;
              } else if(count == 1) {
                //TODO
                HttpEntity entity = msg->getEntity();
                auto content = entity->getContent()->toString();
                HttpUrlEncodedValue encodedValue = HttpUrlEncodedValue::New(content);
                auto map = encodedValue->getValues();

                auto v1 = map->get(String::New("test_tag1"));
                if(v1 == nullptr || !v1->sameAs("test_value1")) {
                     TEST_FAIL("TestHttpResponseWriter Request Encode test1");
                }

                auto v2 = map->get(String::New("test_tag2"));
                if(v2 == nullptr || !v2->sameAs("test_value2")) {
                     TEST_FAIL("TestHttpResponseWriter Request Encode test2");
                }

                if(map->size() != 2) {
                     TEST_FAIL("TestHttpResponseWriter Request Encode test3");
                }


                HttpResponse response = HttpResponse::New();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
                //count = 0;
                latch->countDown();
              }
              break;
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
  printf("port is %d \n",port);
  MyHttpListener listener = MyHttpListener::New();
  HttpServer server = nullptr;
  while(1) {
    server = HttpServerBuilder::New()
                    ->setAddress(Inet4Address::New(port))
                    ->setListener(listener)
                    ->build();
    if (server->start() == -1) {
      port++;
      continue;
    }
    setEnvPort(port);
    break;
  }
  latch->await();
  server->close();

  port++;
  setEnvPort(port);
  
  TEST_OK("TestHttpResponseWriter cookie test100");
}
