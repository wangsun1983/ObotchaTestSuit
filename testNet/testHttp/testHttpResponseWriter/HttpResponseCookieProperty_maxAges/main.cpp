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
#include "Calendar.hpp"
#include "TimeZone.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);
int count = 0;

long setExpires = 0;

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(int event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(NetEvent)::Connect: {
              //connectlatch->countDown();
          }
          break;

          case st(NetEvent)::Message: {
              if(count == 0) {
                //first message to send response with cookie
                HttpResponse response = createHttpResponse();
                HttpCookie cookie1 = createHttpCookie("test2_tag1","test2_value1");
                cookie1->setPropertySecure(true);
                cookie1->setPropertyHttpOnly(true);
                cookie1->setPropertyPath("path123");
                //cookie1->setPropertyDomain("domain123");
                Calendar c = createCalendar();//->getDateTime()
                //c->add(st(Calendar)::DayOfMonth,1);
                printf("time zone is %d \n",st(TimeZone)::getZone());
                setExpires = (c->toTimeMillis())/1000 + 10;

                //cookie1->setPropertyExpires(createHttpDate(c->getGmtDateTime()));
                cookie1->setPropertyMaxAge(10);

                //HttpCookie cookie2 = createHttpCookie("test2_tag2","test2_value2");
                response->getHeader()->addCookie(cookie1);
                //response->getHeader()->addCookie(cookie2);
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
                count++;
              } else if(count == 1) {
                //TODO
                HttpEntity entity = msg->getEntity();
                auto content = entity->getContent()->toString();
                HttpUrlEncodedValue encodedValue = createHttpUrlEncodedValue(content);
                auto map = encodedValue->getValues();

                auto v1 = map->get(createString("test2_tag1"));
                if(v1 == nullptr || !v1->sameAs("test2_value1")) {
                     TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test1");
                }
                
                auto v2 = map->get(createString("path"));
                if(v2 == nullptr || !v2->sameAs("path123")) {
                     TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test2");
                }

                auto v3 = map->get(createString("expires"));
                if(v3->toBasicLong() != setExpires) {
                     TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test3");
                }

                HttpResponse response = createHttpResponse();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
                //count = 0;
                latch->countDown();
                count = 0;
              }
              break;
          }
          break;

          case st(NetEvent)::Disconnect:{
              
          }
          break;
      }
  }
};

int main() {
  MyHttpListener listener = createMyHttpListener();
  HttpServer server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(1256))
                    ->setListener(listener)
                    ->build();
  server->start();
  latch->await();
  server->close();
  sleep(1);
  
  TEST_OK("TestHttpResponseWriter Cookie Property MaxAges test100");
}
